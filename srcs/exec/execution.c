/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:48:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/21 19:48:28 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_cmd(t_pars_list *l)
{
	int			cmd;
	t_pars_node	*node;

	if (!l)
		return (0);
	cmd = 0;
	node = l->head;
	while (node)
	{
		if (node->type == CMD)
			cmd++;
		node = node->next;
	}
	return (cmd);
}

int	pid_zero_execution(t_pars_node *cpy, t_args *args, int data)
{
	delete_content_useless_infiles(args->parser);
	if (exec_builtin_1(args, data) < 0)
	{
		if (cpy->path)
			execve(cpy->path, cpy->cmds, args->env_tab);
	}
	free_all(args);
	exit(0);
	return (0);
}

int	fork_execution(int datas[3], t_pars_node *i, t_pars_list *l, \
		t_args *args)
{
	int			pid;

	if (datas[1] > 1 && pipe(l->pipe) < 0)
		return (-1);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		dup_maestro(datas, l, i);
		pid_zero_execution(i, args, datas[1]);
	}
	if (datas[0] > 1)
		close(datas[2]);
	if (datas[1] > 1)
	{
		datas[2] = l->pipe[0];
		datas[2]--;
		close(l->pipe[1]);
	}
	datas[0]++;
	waitpid(0, NULL, 0);
	return (0);
}

int	loop_execution(t_args *args, t_pars_list *l)
{
	int			datas[3];
	t_pars_node	*i;

	i = l->head;
	datas[0] = 0;
	datas[1] = count_cmd(l);
	datas[2] = 0;
	while (i)
	{
		if (is_builtin(args) || (datas[1] > 1 && !is_builtin(args)))
		{
			if (i->type == CMD)
				fork_execution(datas, i, l, args);
		}
		else
		{
			dup_maestro(datas, l, i);
			exec_builtin_1(args, 1);
			if (i->fds[1] > 0)
				close(i->fds[1]);
		}
		unlink("/tmp/.zuzu");
		i = i->next;
	}
	return (0);
}
