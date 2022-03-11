/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:23 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/11 02:20:43 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int check_simple_files(t_pars_node *n, int *fds)
{
	t_pars_node *node;
	int			fd_out;
	node = n;
	while (node->type == OUTFILE)
		node = node->next;
	fd_out = open(node->content, F_OK);
	if (fd_out < 0)
		return (-1);
	else
		fds[1] = fd_out;
	return (0);
}

char	**create_fd_tab(t_pars_node *inf, t_pars_node *out)
{
	char		**fds;
	int			size;

	size = 0;
	fds = NULL;
	// printf("out = %s\n", out->content);
	if (inf)
		size++;
	if (out)
		size++;
	if (size == 0)
		return (NULL);
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

char	**init_fds(t_pars_list *l)
{
	t_pars_node	*i;
	t_pars_node	*out;
	t_pars_node	*inf;
	char		**fds;

	i = l->head;
	inf = NULL;
	out = NULL;
	while (i)
	{
		if (i->type == INFILE)
			inf = i;
		if (i->type == OUTFILE)
			out = i;
		else if (i->type == SUPER_OUTFILE)
			out = i;
		i = i->next;
	}
	fds = create_fd_tab(inf, out);
	return (fds);
}

int	simple_exec(t_args *args, t_pars_list *l)
{
	int		pid;
	char	**fds_content;
	int		in_out[2];
	int		fd_tab[2];

	pid = fork();
	if (pid == -1)
		return (-1);
	// printf("infile = %d outfile = %d", infile, outfile);
	// gerer infile celui qui fonctionnera sera celui qui sera en dernier
	// gerer outfile on va chercher le dernier aussi et on va verifier s'il existe ou pas 
	// mais on ne va pas le creer si ça fail.
	// gerer heredoc 
	fd_tab[0] = 0;
	fd_tab[1] = 0;
	in_out[0] = 0;
	in_out[1] = 0;
	if (pid == 0)
	{
		fds_content = init_fds(l);
		create_infiles_outfiles(l, in_out, fd_tab, fds_content);
		if (fd_tab[0] > 0)
			dup2(fd_tab[0], 0);
		if (fd_tab[1] > 0)
			dup2(fd_tab[1], 1);
		delete_content_useless_infiles(l);
		if (is_builtin_1(args) < 0)
			execve(l->head->path, l->head->cmds, args->env_tab);
		exit(0);
	}
	return (0);
}
