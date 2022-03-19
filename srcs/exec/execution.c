/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:23 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/19 18:35:52 by dyoula           ###   ########.fr       */
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
	printf("cpy[0] = %d\n", cpy->fds[0]);
	delete_content_useless_infiles(args->parser);
	if (is_builtin_1(args) < 0)
		execve(cpy->path, cpy->cmds, args->env_tab);

	// free_all(args);
	// exit(127);
	// if (datas[0] == 0)
	// {
	// 	if (cpy->path)
	// 		printf("%s\n", cpy->path);
	// 	if (cpy->fds[0] > 0)
	// 	{
	// 		printf("1\n");
	// 		dup2(cpy->fds[0], 0);
	// 	}
	// 	if (cpy->fds[1] > 0)
	// 	{
	// 		printf("2\n");			
	// 		dup2(cpy->fds[1], 1);
	// 	}
	// 	else if (datas[1] > 1)
	// 	{
	// 		printf("3\n");	
	// 		dup2(args->parser->pipe[1], 1);
	// 	}
	// 	// faire les closes ici
	// 	// if (cpy->fds[0] > 0)
	// 	// 	close(cpy->fds[0]);
	// 	// if (cpy->fds[1])
	// 	// 	close(cpy->fds[1]);
	// 	close(args->parser->pipe[0]);
	// 	close(args->parser->pipe[1]);
	// 	delete_content_useless_infiles(args->parser);
	// 	if (is_builtin_1(args) < 0)
	// 		execve(cpy->path, cpy->cmds, args->env_tab);
	// 	// free_all(args);
	// 	// exit(127);
	// }
	// else if (datas[0] == datas[1])
	// {
	// 	if (cpy->path)
	// 		printf("%s\n", cpy->path);
	// 	if (cpy->fds[0] > 0)
	// 		dup2(cpy->fds[0], 0);
	// 	else
	// 		dup2(datas[2], 0);
	// 	if (cpy->fds[1] > 0)
	// 		dup2(cpy->fds[1], 1);
	// 	// faire les closes ici
	// 	// if (cpy->fds[1] > 0)
	// 	// 	close(cpy->fds[1]);
	// 	// if (cpy->fds[0])
	// 	// 	close(cpy->fds[0]);
	// 	close(datas[3]);
	// 	close(args->parser->pipe[0]);
	// 	close(args->parser->pipe[1]);
	// 	delete_content_useless_infiles(args->parser);
	// 	if (is_builtin_1(args) < 0)
	// 		execve(cpy->path, cpy->cmds, args->env_tab);
	// 	// free_all(args);
	// 	// exit(127);
	// }
	// else
	// {
	// 	if (cpy->fds[0] > 0)
	// 		dup2(cpy->fds[0], 0);
	// 	else
	// 		dup2(datas[2], 0);
	// 	if (cpy->fds[1] > 0)
	// 		dup2(cpy->fds[1], 1);
	// 	else
	// 		dup2(args->parser->pipe[1], 1);
	// 	// faire les closes
	// 	close(args->parser->pipe[0]);
	// 	close(args->parser->pipe[1]);
	// 	close(datas[2]);
	// 	// if (cpy->fds[1])
	// 	// 	close(cpy->fds[1]);
	// 	// if (cpy->fds[0])
	// 	// 	close(cpy->fds[0]);
	// 	if (is_builtin_1(args) < 0)
	// 		execve(cpy->path, cpy->cmds, args->env_tab);
	// 	// free_all(args);
	// 	// exit(127);
	// }
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
	(void)args;
	while (i)
	{
		if (i->type == CMD)
		{
			if (datas[1] > 1 && pipe(l->pipe) < 0) // ca maarche
				return (-1);
			pid = fork();
			if (pid == -1)
				return (-1);
			if (pid == 0)
			{
				printf("datas[0] = %d\n", datas[0]);
				printf("%s\n", i->path);
				// la liste chainee a l'air d'etre morte 
				dup_maestro(datas, l, i);
				pid_zero_execution(i, args);
				exit (0);
			}
			waitpid(0, NULL, 0);
			if (datas[0] > 1)
				close(datas[2]);
			if (args->nb_commands > 1)
			{
				datas[2] = l->pipe[0];
				close(l->pipe[1]);
			}
		}
		datas[0]++;
		i = i->next;
	}
	return (0);
}
