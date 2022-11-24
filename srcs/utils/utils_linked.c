/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:34:19 by emtran            #+#    #+#             */
/*   Updated: 2022/03/03 00:49:32 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	add_node_after_current(char *content, t_pars_node *n, t_pars_list *l)
{
	t_pars_node	*node;

	if (!content || !n || content[0] == 0)
		return (0);
	node = malloc(sizeof(t_pars_node));
	if (!node)
		return (0);
	init_parsing_node(node);
	node->content = ft_strdup(content);
	node->next = n->next;
	node->previous = n;
	n->next = node;
	l->length++;
	return (1);
}
