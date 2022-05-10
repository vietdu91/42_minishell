/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribution_norm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:23:04 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 14:04:52 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	apply_cmd(t_pars_node *node, int type)
{
	node->type = type;
	if (node->previous && node->previous->type == 0)
		node->previous->type = CMD;
	if (node->next)
		node->next->type = CMD;
}

int	apply_type(int type, t_pars_node *node)
{
	node->type = type;
	return (1);
}

void	arg_attribution(t_pars_list *l)
{
	t_pars_node	*node;
	int			cmds;

	cmds = 0;
	node = l->head;
	while (node)
	{
		if (node->type != CMD && node->type != OPTION && \
		node->type != SIMPLE_ARG)
			cmds = 0;
		if (cmds == 1 && node->type == EMPTY)
			node->type = SIMPLE_ARG;
		if (node->type == CMD || node->type == PIPE)
			cmds = 1;
		node = node->next;
	}
}
