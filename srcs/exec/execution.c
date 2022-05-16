/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:48:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/16 21:50:07 by dyoula           ###   ########.fr       */
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
			ft_close(datas[2], l->pid + 1000000);
		if (datas[1] > 1)
		{
			datas[2] = l->pipe[0];
			ft_close(l->pipe[1], l->pid + 2000000);
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
	l->pid = 0;
	if (datas[1] > 1)
	{
		if (pipe(l->pipe) < 0)
			return (-1);
		ft_putstr("Open fd ", 2);
		ft_putnbr(l->pipe[0], 2);
		ft_putstr(" et ", 2);
		ft_putnbr(l->pipe[1], 2);
		ft_putstr("\n", 2);
	}
	if (which_node(l, datas[0]) || (!which_node(l, datas[0])))
	{
		l->pid = fork();
		if (l->pid == -1)
			return (-1);
		if (l->pid == 0)
		{
			ft_putstr("New pid\n", 2);
			dup_pid(i, args, datas, 1);
		}
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
	printf("datas[2] = %d\n", datas[2]);
	// signal(SIGINT, &signal_ignore);
	// signal(SIGQUIT, &signal_ignore);
	while (i)
	{
		if (i->type == CMD || !i->len)
		{
			datas[0]++;
			printf("CONTENT : %s - TYPE : %d - LEN : %d\n", i->content, i->type, i->len);			
			printf("1   HELLOOOO %d\n", i->fds[1]);
			if ((is_builtin(i) || (!is_builtin(i) && datas[1] > 1)))
				fork_execution(datas, i, l, args);
			else
				dup_pid(i, args, datas, 0);
			close_loop_execution(i, l, datas);
		}
		i = i->next;
	}
	close_loop_execution_parent(j, l, datas);
	return (0);
}
