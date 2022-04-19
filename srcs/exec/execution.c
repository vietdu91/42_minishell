/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:48:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/19 16:20:13 by dyoula           ###   ########.fr       */
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
	//  printf("cpy[0] = %d\n", cpy->fds[0]);
	//  printf("cmds = [%s]\n", cpy->cmds[0]);
	//  printf("path = %s\n", cpy->path);
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

int	loop_execution(t_args *args, t_pars_list *l)
{
	int			pid;
	// int	tmp;
	int			datas[3]; // no_cmd, nbr_cmd, tmp
	t_pars_node *i;

	i = l->head;
	datas[0] = 0; // numero cmd
	datas[1] = count_cmd(l); // nombre de cmd
	datas[2] = 0; //tmp
	while (i)
	{
		if (is_builtin(args) || (datas[1] > 1 && !is_builtin(args)))
		{
			if (i->type == CMD)
			{
				// printf("infile fd = %d\n", i->fds[0]);
				if (datas[1] > 1 && pipe(l->pipe) < 0) // ca maarche
					return (-1);
				pid = fork();
				if (pid == -1)
					return (-1);
				if (pid == 0)
				{
					// printf("salut\n");
					// printf("datas[0] = %d\n", datas[0]);
					dup_maestro(datas, l, i);
					// ft_putnbr(STDIN_FILENO, 2);
					// printf("<-\n");
					pid_zero_execution(i, args, datas[1]);
					// exit (0);
				}
				if (datas[0] > 1)
					close(datas[2]);
				if (datas[1] > 1)
				{
					datas[2] = l->pipe[0];
					datas[2]--;
					// ft_putnbr(datas[2], 2);
					// ft_putstr("\n", 2);
					close(l->pipe[1]);
				}
				datas[0]++;
				waitpid(0, NULL, 0);
			}
		}
		else
		{
			// printf("yosa\n");
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
