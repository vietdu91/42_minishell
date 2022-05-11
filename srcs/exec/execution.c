/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:48:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/11 21:26:27 by dyoula           ###   ########.fr       */
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

int	reset_in_out(int datas[5], t_pars_list *l, int n)
{
	if (n == 1)
	{
		dup2(datas[3], STDIN_FILENO);
		dup2(datas[4], STDOUT_FILENO);
	}
	else if (n == 2)
	{
		if (datas[0] > 1)
			close(datas[2]);
		if (datas[1] > 1)
		{
			datas[2] = l->pipe[0];
			close(l->pipe[1]);
		}
	}
	return (0);
}

int	pid_zero_execution(t_pars_node *cpy, t_args *args, int data, int datas[5])
{
	int		error;

	error = 0;
	if (exec_builtin_1(args, cpy, data, datas) < 0)
	{
		if (cpy->path)
		{
			execve(cpy->path, cpy->cmds, args->env_tab);
			if (errno == 2)
				error = 127;
			if (errno == 13)
				error = 126;
			print_error(BASH, NULL, *cpy->cmds, strerror(errno));
			ft_putchar('\n', 2);
			free_all(args);
			exit (error);
		}
	}
	return (0);
}

int	fork_execution(int datas[5], t_pars_node *i, t_pars_list *l, \
	t_args *args)
{
	int			pid;

	pid = 0;
	if (datas[1] > 1)
	{
		if (pipe(l->pipe) < 0)
			return (-1);
	}
	if (which_node(l, datas[0]) || (!which_node(l, datas[0])))
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
			dup_pid(i, args, datas, 1);
	}
	else
		dup_pid(i, args, datas, 0);
	reset_in_out(datas, l, 2);
	return (0);
}

int	loop_execution(t_args *args, t_pars_list *l)
{
	int			datas[5];
	t_pars_node	*i;
	int			j;

	j = 0;
	i = l->head;
	datas[0] = 0;
	datas[1] = count_cmd(l);
	datas[2] = 0;
	datas[3] = dup(0);
	datas[4] = dup(1);
	signal(SIGINT, &signal_ignore);
	signal(SIGQUIT, &signal_ignore);
	while (i)
	{
		if (i->type == CMD || !i->len)
		{
			datas[0]++;
			fork_execution(datas, i, l, args);
			close_loop_execution(i, l, datas);
		}
		i = i->next;
	}
	close_loop_execution_parent(j, l, datas);
	return (0);
}
