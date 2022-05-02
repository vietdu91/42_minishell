/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:04:23 by emtran            #+#    #+#             */
/*   Updated: 2022/05/02 22:20:31 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_env_node(t_env	*node)
{
	free(node->line);
	free(node->variable);
	free(node->content);
	free(node->content_trim);
	free(node);
	node = NULL;
}

void	delete_pars_node(t_pars_node *node)
{
	if (!node)
		return ;
	if (node->next)
		node->previous->next = node->next;
	if (node->previous)
		node->next->previous = node->previous;
	free(node->content);
	free(node->nw_content);
	free(node->content_exp);
	free(node->content_exp_sans_q);
	free(node);
	node = NULL;
}

void	free_content_env_node(t_env *node)
{
	free(node->line);
	free(node->variable);
	free(node->content);
	free(node->content_trim);
}
