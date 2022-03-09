/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:23 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/08 20:47:04 by dyoula           ###   ########.fr       */
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
	{
		fds[1] = fd_out;
	}
	return (0);
}

char	**create_fd_tab(t_pars_node *inf, t_pars_node *out)
{
	char		**fds;
	int			size;

	size = 0;
	fds = NULL;
	printf("out = %s\n", out->content);
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
	int			files;

	files = 0;
	i = l->head;
	inf = NULL;
	out = NULL;
	while (i)
	{
		if (i->type == INFILE)
		{
			inf = i;
			printf("inf = %s\n", inf->content);
			files++;
		}
		if (i->type == OUTFILE)
		{
			out = i;
			while (out && out->next && out->next->type == OUTFILE)
				out = out->next;
			files++;
		}
		i = i->next;
	}
	fds = create_fd_tab(inf, out);
	return (fds);
}

int	simple_exec(t_args *args, t_pars_list *l)
{
	int	pid;
	char	**fds;
	int		infile;
	int		outfile;

	pid = fork();
	if (pid == -1)
		return (-1);
	// printf("infile = %d outfile = %d", infile, outfile);
	// gerer infile celui qui fonctionnera sera celui qui sera en dernier
	// gerer outfile on va chercher le dernier aussi et on va verifier s'il existe ou pas 
	// mais on ne va pas le creer si ça fail.
	// gerer heredoc 
	if (pid == 0)
	{
		fds = init_fds(l);
		infile = 0;
		outfile = 0;
		if (fds && fds[0])
			infile = open(fds[0], O_RDONLY);
		printf("fds[1] = %s\n", fds[1]);
		if (fds && fds[1])
			outfile = open(fds[1], O_WRONLY | O_CREAT, 0664);
		printf("outfile = %d\n", outfile);
		if (infile > 0)
			dup2(infile, 0);
		if (outfile > 0)
			dup2(outfile, 1);
		execve(l->head->path, l->head->cmds, args->env_tab);
		// free
		exit(0);
	}
	return (0);
}
