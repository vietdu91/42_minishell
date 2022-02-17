/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribution_norm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:23:04 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/08 19:19:02 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	apply_cmd(t_pars_node *node, int type)
{
	node->type = type;
	if (node ->previous && node->previous->type == 0)
		node->previous->type = CMD;
	if (node->next)
		node->next->type = CMD;
}

int	apply_type(int type, t_pars_node *node)
{
	node->type = type;
	return (1);
}
