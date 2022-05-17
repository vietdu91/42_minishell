/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:20:58 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/17 16:37:44 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_in(t_pars_list *l)
{
	t_pars_node	*i;

	i = l->head;
	while (i)
	{
		if (i->type == INFILE)
			return (1);
		else if (i->type == HEREDOC)
			return (2);
		i = i->next;
	}
	return (0);
}

int	find_out(t_pars_list *l)
{
	t_pars_node	*i;

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

void	delete_content_useless_infiles(t_pars_list *l)
{
	t_pars_node	*i;
	int			last;
	int			fd;

	last = 1;
	i = l->tail;
	while (i)
	{
		fd = -1;
		if (i->type == PIPE)
			last = 1;
		if ((i->type == OUTFILE || i->type == SUPER_OUTFILE) && last == 0)
		{
			unlink(i->content);
			fd = open(i->content, O_WRONLY | O_CREAT | O_TRUNC, 0664);
			ft_close(fd, "delete useless");
		}
		if ((i->type == OUTFILE || i->type == SUPER_OUTFILE) && last == 1)
			last--;
		i = i->previous;
	}
}

int	size_2dtab(char **dtab)
{
	int	i;

	if (!dtab || !(*dtab))
		return (-1);
	i = 0;
	while (dtab[i])
		i++;
	return (i);
}

void	create_infiles_outfiles(t_args *args, int in_out[2], \
		t_pars_node *cpy, char **fds_content)
{
	int	hdoc_number;

	hdoc_number = 0;
	if (!fds_content)
		return ;
	in_out[0] = find_in(args->parser);
	in_out[1] = find_out(args->parser);
	if (in_out[0] == 1 && fds_content[0])
		cpy->fds[0] = open(fds_content[0], O_RDONLY, 0664);
	else if (in_out[0] == 2 && fds_content[0])
	{
		hdoc_number = size_2dtab(args->hdocs) - 1;
		cpy->fds[0] = open("/tmp/.zuzu", O_WRONLY | O_CREAT | O_TRUNC, 0664);
		if (cpy->fds[0] > 0)
			ft_putstr(args->hdocs[hdoc_number], cpy->fds[0]);
		close(cpy->fds[0]);
		cpy->fds[0] = open("/tmp/.zuzu", O_RDONLY | O_CREAT, 0664);
	}
	if (in_out[1] == 1 && fds_content[1])
		cpy->fds[1] = open(fds_content[1], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	else if (in_out[1] == 2 && fds_content[1])
		cpy->fds[1] = open(fds_content[1], O_WRONLY | O_CREAT | O_APPEND, 0664);
	if (cpy->fds[0] == -1 || cpy->fds[1] == -1)
		free_all(args);
	return ;
}
