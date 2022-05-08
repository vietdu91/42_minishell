/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:48:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/08 23:32:22 by dyoula           ###   ########.fr       */
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

int	reset_in_out(int datas[5], t_pars_list *l)
{
	// if (dup2(datas[3], STDIN_FILENO) < 0 || dup2(datas[4], STDOUT_FILENO) < 0)
	// {
	// 	close_maestro(datas, l);
	// 	return (-1);
	// }
	(void)l;
	dup2(datas[3], STDIN_FILENO);
	dup2(datas[4], STDOUT_FILENO);
	return (0);
}

int	pid_zero_execution(t_pars_node *cpy, t_args *args, int data, int datas[5])
{
	int		error;

	error = 0;
	// ft_putstr(cpy->content, 1);
	// delete_content_useless_infiles(args->parser);
	// ft_putstr("Fin de commande builtin \n", 1);
//	ft_putnbr(exec_builtin_1(args, cpy, data), 2);
//	ft_putstr("\n\n\n", 2);
	// int i = 0;
	// while (cpy->cmds[i])
	// {
	// 	printf("CMD %d : %s\n", i, cpy->cmds[i]);
	// 	i++;
	// }
	if (exec_builtin_1(args, cpy, data, datas) < 0)
	{
		//ft_putstr("LOL\n", 2);
		if (cpy->path)
		{
			// ft_putstr("Fin de commande exec\n", 2);
			//ft_putstr("Fin de commande exec 2\n", 2);
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
	if (which_node(l, datas[0]) || (!which_node(l, datas[0]) && datas[1] > 1))
	{
		pid = fork();
		if (pid == -1)
			return (-1);
		if (pid == 0)
		{
		//	signal(SIGINT, SIG_DFL);
		//	signal(SIGQUIT, SIG_DFL);
			dup_maestro(datas, l, i);
			pid_zero_execution(i, args, datas[1], datas);
			free_all(args);
			exit (g_exit_status);
		}
	}
	else
	{
		dup_maestro(datas, l, i);
		pid_zero_execution(i, args, datas[1], datas);
		// reset_in_out(datas, l);
	}
	{
		if (datas[0] > 1)
			close(datas[2]);
		if (datas[1] > 1)
		{
			// printf("quand datas[0] = %d l->pipe [0] %d\n", datas[0], l->pipe[0]);
			datas[2] = l->pipe[0];
			close(l->pipe[1]);
		}
		// if ((0 < waitpid(0, &status, 0) && (WIFEXITED(status))))
		// 	g_exit_status = WEXITSTATUS(status);
		// if (WIFSIGNALED(status))
		// 	handle_status(WTERMSIG(status));
		// ft_putstr("hehehe\n", 2);
	}
	return (0);
}

// int	mega_closer(t_pars_list *l)
// {
// 	t_pars_node	*i;

// 	i = l->head;
// 	while (i)
// 	{
// 		i = i->next;
// 	}
// 	return (0);
// }

// void	restore_fd(int val)
// {
// 	static int	fd_in = -1;
// 	static int	fd_out = -1;

// 	if (val)
// 	{
// 		fd_in = dup(STDIN_FILENO);
// 		...
// 	}
// 	else{
// 		dup2(STDIN_FILENO, fd_in);
// 		...//
// 		close(fd_in);
// 		close(fd_out);
// 	}
// }

int	loop_execution(t_args *args, t_pars_list *l)
{
	int			datas[5];
	t_pars_node	*i;
	int			j;
	int			status;


	j = 0;
	i = l->head;
	status = 0;
	datas[0] = 0;
	datas[1] = count_cmd(l);
	datas[2] = 0;
	datas[3] = dup(0);
	datas[4] = dup(1);
	printf("%d\n", datas[4]);
	signal(SIGINT, &signal_ignore);
	signal(SIGQUIT, &signal_ignore);
	while (i)
	{
		if (i->type == CMD || !i->len)
		{
			datas[0]++;
			// int j = -1;
			// while (i->cmds[++j])
			// 	printf("kontent %s\n", i->cmds[j]);
			fork_execution(datas, i, l, args);
			// if (datas[1] == datas[0])
			// {
			// 	close_maestro(datas, l, i);
			// }
			// if (datas[1] == 1)
			// 	reset_in_out(datas, l);
			if (i->fds[0] > 0)
				close(i->fds[0]);
			if (i->fds[1] > 0)
				close(i->fds[1]);
			if (datas[0] > 1)
				close(l->pipe[1]);
			if (i->previous && l->pipe[1] > 0 &&  i->previous->type == PIPE)
				close(l->pipe[1]);
			// printf("kontent = %s\n", i->content);
			// close(datas[3]); // je fais bugger le multipipe 
			// close(datas[4]); // je fais bugger le multipipe 
		}
		i = i->next;
	}
	while (j < l->length)
	{
		if ((0 < waitpid(0, &status, 0) && (WIFEXITED(status))))
			g_exit_status = WEXITSTATUS(status);
		j++;
	}	
	unlink("/tmp/.zuzu");
	close(datas[3]);
	close(datas[4]);
	if (l->pipe[0] > 0)
		close(l->pipe[0]);
	if (l->pipe[1] > 0)
		close(l->pipe[1]);
	// reset_in_out(datas, l);
	// close(0); // je fais exit le programme 
	// close(1); // je cree une boucle infinie 
	return (0);
}
