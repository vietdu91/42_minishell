/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:53:09 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/13 02:37:48 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_heredoc(t_pars_list *l)
{
	int			i;
	t_pars_node	*node;

	i = 0;
	node = l->head;
	while (node)
	{
		if (node->type == LIMITATOR)
			i++;
		node = node->next;
	}
	return (i);
}

int	fill_d_tab_heredoc(t_args *args, int size, char **eof)
{
	int	i;

	if (!size)
		return (0);
	i = 0;
	memset(&args->hdocs, 0, sizeof(args->hdocs));
	args->hdocs = malloc(sizeof(char *) * (size + 1));
	if (!args->hdocs)
		return (-1);
	while (i < size)
	{
		args->hdocs[i] = NULL;
		if (!read_heredoc(&args->hdocs[i], eof[i]))
		{
			malloc_failed(args->hdocs, i);
			return (-2);
		}
		i++;
	}
	args->hdocs[i] = NULL;
	return (1);
}
