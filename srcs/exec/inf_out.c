/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:23 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/25 18:53:41 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char **create_fd_tab(t_pars_node *inf, t_pars_node *out)
{
	char **fds;

	fds = NULL;
	// printf("out = %s\n", out->content);
	fds = malloc(sizeof(char *) * 3);
	if (!fds)
		return (NULL);
	fds[0] = NULL;
	if (inf)
		fds[0] = ft_strdup(inf->content);
	fds[1] = NULL;
	if (out)
		fds[1] = ft_strdup(out->content);
	fds[2] = NULL;
	return (fds);
}

char **fill_fds(t_pars_node *cpy)
{
	t_pars_node *i;
	t_pars_node *infile;
	t_pars_node *outfile;
	char **fds;

	infile = NULL;
	outfile = NULL;
	i = cpy;
	while (i && i->type != PIPE)
	{
		if (i->type == INFILE || i->type == LIMITATOR)
			infile = i;
		if (i->type == OUTFILE)
			outfile = i;
		else if (i->type == SUPER_OUTFILE)
			outfile = i;
		i = i->next;
	}
	fds = create_fd_tab(infile, outfile);
	return (fds);
}

int inf_out_maestro(t_args *args, t_pars_list *l)
{
	int		pid;
	int 	status;
	char	**fds_content;
	int		in_out[2];
	int		fd_tab[2];

	status = 0;
	pid = fork();
	if (pid == -1)
		return (-1);
	// gerer heredoc 
	fd_tab[0] = 0;
	fd_tab[1] = 0;
	in_out[0] = 0;
	in_out[1] = 0;
	i = l->head;
	while (i)
	{
<<<<<<< HEAD:srcs/exec/inf_out.c
		if (i->type == CMD)
		{
			fds_content = fill_fds(i);
			create_infiles_outfiles(args, in_out, i, fds_content);
			// printf("infile = %d\n", i->fds[0]);
		}
		i = i->next;
=======
		fds_content = init_fds(l);
		create_infiles_outfiles(args, in_out, fd_tab, fds_content);
		// printf("fd 0 = %d\n", fd_tab[0]);
		if (fd_tab[0] > 0)
			dup2(fd_tab[0], 0);
		if (fd_tab[1] > 0)
			dup2(fd_tab[1], 1);
		delete_content_useless_infiles(l);
		if (is_builtin_1(args) < 0 && is_builtin_2(args) < 0)
			execve(l->head->path, l->head->cmds, args->env_tab);
		exit(0);
>>>>>>> 52c75480964d5b2d953310054ee25c2460ed192a:srcs/exec/exec_map.c
	}
<<<<<<< HEAD
	waitpid(pid, &status, 0);
	return (0);
=======
	if (fds_content)
		free_d_tab(fds_content);
	return (1);
>>>>>>> d087592482836f4c31489dd9e83fac81fc15b03c
}
