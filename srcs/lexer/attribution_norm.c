/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribution_norm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:23:04 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/05 23:29:11 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	apply_cmd(t_pars_node *node)
{
	if (node->previous->type == 0)
		node->previous->type = CMD;
	node->next->type = CMD;
}
