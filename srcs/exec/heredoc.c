/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:53:09 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/02 19:05:07 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_heredoc(t_pars_list *l)
{
	int			i;
	t_pars_node *node;

	i = 0;
	node = l->head;
	while (node)
	{
		if (node->type == 18)
			i++;
		node = node->next;	
	}
	printf("heredoc = %d\n", i);
	return (i);
}

int	fill_d_tab_heredoc(t_exec *args_exec, int size, char **eof)
{
	int	i;

	if (!size)
		return (0);
	i = 0;
	args_exec->heredocs = malloc(sizeof(char *) * (size + 1));
	if (!args_exec->heredocs)
		return (-1);
	while (i < size)
	{
		args_exec->heredocs[i] = NULL;
		if (!read_heredoc(args_exec->heredocs[i], eof[i]))
		{
			malloc_failed(args_exec->heredocs, i);
			return (-2);
		}
		i++;
	}
	return (1);
}
