/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:57:13 by emtran            #+#    #+#             */
/*   Updated: 2022/01/14 17:20:29 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_all(t_args *args)
{
	if (!args)
		return ;
	if (args->buffer)
		free(args->buffer);
	rl_clear_history();
	args = NULL;
}

void	free_d_tab(char **tb)
{
	int	i;

	i = -1;
	if (!tb)
		return ;
	while (tb[++i])
	{
		if (tb[i])
			free(tb[i]);
	}
	free(tb);
	tb = NULL;
}

void	free_t_lists(t_list *c)
{
	t_node	*del;
	t_node	*i;

	if (!c)
		return ;
	i = c->head;
	while (i)
	{
		del = i;
		free_d_tab(del->cmd);
		free(del->content);
		i = i->next;
		free(del);
	}
	free(c);
}
