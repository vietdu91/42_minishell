/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:48:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/23 21:08:58 by dyoula           ###   ########.fr       */
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
	// ft_putstr(cpy->content, 1);
	delete_content_useless_infiles(args->parser);
	// ft_putstr("Fin de commande builtin \n", 1);
	if (exec_builtin_1(args, cpy, data) < 0)
	{
		if (cpy->path)
		{
			ft_putstr("Fin de commande exec\n", 2);
			execve(cpy->path, cpy->cmds, args->env_tab);
			ft_putstr("Fin de commande exec 2\n", 2);
		}
	}
	// free_all(args);
	// exit(0);
	return (0);
}

int	fork_execution(int datas[3], t_pars_node *i, t_pars_list *l, \
	t_args *args)
{
	int			pid;

	pid = 0;
	if (datas[1] > 1)
	{
		if (pipe(l->pipe) < 0)
			return (-1);
		// printf("j'ai fait un pipe \n");
	}
	else
	{
		// printf("je suis sorti\n");
	}
	// printf("datas[0] = %d && datas[1]%d\n", datas[0], datas[1]);
	// printf("datas[0] == %d\n", datas[0]);
	if (which_node(l, datas[0]))
	{
		pid = fork();
		printf("fork 1\n");
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
			dup_maestro(datas, l, i);
			printf("coucou1\n");
			pid_zero_execution(i, args, datas[1]);
			printf("coucou2\n");
			exit (0);
		}
		// return (0);
	}
	// else if ( (!which_node(l, datas[0]) && datas[1] > 1))
	// {
	// 	pid = fork();
	// 	printf("fork 2\n");
	// }
	
	{
		if (datas[0] > 1)
			close(datas[2]);
		if (datas[1] > 1)
		{
			printf("quand datas[0] = %d l->pipe [0] %d\n", datas[0], l->pipe[0]);
			datas[2] = l->pipe[0];
			// datas[2]--;
			close(l->pipe[1]);
		}
		datas[0]++;
		waitpid(0, NULL, 0);
	}
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
		printf("kontent = %s\n", i->content);
		if (i->type == CMD)
		{
			datas[0]++;
			fork_execution(datas, i, l, args);

			unlink("/tmp/.zuzu");
		}
		i = i->next;
	}
	return (0);
}
