/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:23 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/25 14:24:25 by dyoula           ###   ########.fr       */
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

int	pid_zero_execution(t_pars_node *cpy, t_args *args)
{
	//  printf("cpy[0] = %d\n", cpy->fds[0]);
	//  printf("cmds = [%s]\n", cpy->cmds[0]);
	//  printf("path = %s\n", cpy->path);
	delete_content_useless_infiles(args->parser);
	if (is_builtin_1(args) < 0)
		execve(cpy->path, cpy->cmds, args->env_tab);
	exit(0);
	return (0);
}

int	loop_execution(t_args *args, t_pars_list *l)
{
	int	pid;
	// int	tmp;
	int			datas[3]; // no_cmd, nbr_cmd, tmp
	t_pars_node *i;

	i = l->head;
	datas[0] = 0; // numero cmd
	datas[1] = count_cmd(l); // nombre de cmd
	datas[2] = 0; //tmp
	args->nb_commands = how_many_commands(args->buffer);
	// printf("CMDS %d\n", args->nb_commands);
	while (i)
	{
		if ((args->nb_commands > 0 && !is_builtin(args)) || is_builtin(args))
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
					// printf("datas[0] = %d\n", datas[0]);
					// printf("%s\n", i->path);
					// la liste chainee a l'air d'etre morte 
					dup_maestro(datas, l, i);
					pid_zero_execution(i, args);
					exit (0);
				}
				if (datas[0] > 1)
					close(datas[2]);
				if (args->nb_commands > 1)
				{
					datas[2] = l->pipe[0];
					close(l->pipe[1]);
				}
				datas[0]++;
				waitpid(0, NULL, 0);
			}
		}
		else
			is_builtin_1(args);
		i = i->next;
	}
	return (0);
}
