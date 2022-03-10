/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:20:58 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/10 20:40:18 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* 
init_fds va d'abord enregistrer les addresses
de infile et outfile.
puis il va remplir les fds avec create fd_tab.

idee: 
    y ajouter le pointeur de infile du maestro
afin d'indiquer si c'est un heredoc ou un infile
et si c'est un simple file ou un super outfile.

create fd_tab:
va checker le tableau de fds et lui mettre les
contents respectifs.

du coup avec le infile on va pouvoir indiquer quelle
fonction utiliser pour la creation des fichiers.
*/
int	find_in(t_pars_list *l)
{
	t_pars_node *i;

	i = l->head;
	while (i)
	{
		if (i->type == INFILE)
			return(1);
		else if (i->type == HEREDOC)
			return (2);
		i = i->next;
	}
	return (0);
}

int	find_out(t_pars_list *l)
{
	t_pars_node *i;

	i = l->tail;
	while (i)
	{
		if (i->type == OUTFILE)
			return (1);
		else if (i->type == SUPER_OUTFILE)
			return (2);	
		i = i->previous;
	}
	return (0);
}

void		create_infiles_outfiles(t_pars_list *l, int in_out[2],\
		int fd_tab[2], char **fds_content)
{
	if (!fds_content)
		return ;
	in_out[0] = find_in(l);
	in_out[1] = find_out(l);
	if (in_out[0] == 1 && fds_content[0])
		fd_tab[0] = open(fds_content[0], O_RDONLY);
	if (in_out[1] == 1 && fds_content[1])
		fd_tab[1] = open(fds_content[1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else if (in_out[1] == 2  && fds_content[1])
		fd_tab[1] = open(fds_content[1], O_WRONLY | O_CREAT | O_APPEND, 0664);
	return ;
}
