/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:15:04 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/15 20:59:32 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

char	**fill_fds(t_pars_node *cpy)
{
    t_pars_node *i;
	t_pars_node	*infile;
	t_pars_node	*outfile;
	char		**fds;

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

int	inf_out_maestro(t_args *args, t_pars_list *l)
{
	t_pars_node *i;
	int			in_out[2]; // dans le node desormais 
	// int		fd_tab[2];
	char		**fds_content;

	in_out[0] = 0;
	in_out[1] = 0;
	i = l->head;
	while (i)
	{
		if (i->type == CMD)
		{
			fds_content = fill_fds(i);
			create_infiles_outfiles(args, in_out, i, fds_content);
		}
		i = i->next;
	}
	(void)args;
	return (1);
}
