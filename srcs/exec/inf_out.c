/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:23 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/17 16:39:54 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**create_fd_tab(t_pars_node *inf, t_pars_node *out)
{
	char	**fds;

	fds = NULL;
	fds = malloc(sizeof(char *) * 3);
	if (!fds)
		return (NULL);
	fds[0] = ft_strdup("");
	if (inf)
	{
		free(fds[0]);
		fds[0] = ft_strdup(inf->content_exp_sans_q);
	}
	fds[1] = ft_strdup("");
	if (out)
	{
		free(fds[1]);
		fds[1] = ft_strdup(out->content_exp_sans_q);
	}
	fds[2] = NULL;
	return (fds);
}

int	file_create_loop(t_pars_list *l)
{
	t_pars_node	*i;
	int			fd;

	i = l->head;
	while (i)
	{
		fd = -1;
		if (i->type == INFILE || i->type == SUPER_OUTFILE)
		{
			fd = open(i->content, O_WRONLY | O_CREAT, 0664);
			close(fd);
		}
		i = i->next;
	}
	return (0);
}

char	**fill_fds(t_pars_node *cpy)
{
	t_pars_node	*i;
	t_pars_node	*infile;
	t_pars_node	*outfile;
	char		**fds;

	infile = NULL;
	outfile = NULL;
	i = cpy;
	while (i && i->type != PIPE)
	{
		if (i->type == INFILE)
			infile = i;
		if (i->type == OUTFILE)
			outfile = i;
		i = i->previous;
	}
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

int	inf_out_maestro(t_args *args, t_pars_list *l)
{
	t_pars_node	*i;
	char		**fds_content;
	int			in_out[2];

	fds_content = NULL;
	in_out[0] = 0;
	in_out[1] = 0;
	i = l->head;
	while (i)
	{
		if (i->type == CMD)
		{
			fds_content = fill_fds(i);
			create_infiles_outfiles(args, in_out, i, fds_content);
			if (fds_content)
				free_d_tab(fds_content);
			fds_content = NULL;
		}
		i = i->next;
	}
	return (1);
}
