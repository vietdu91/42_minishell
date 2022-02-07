/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:53:10 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/07 16:38:12 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	init_parsing_list(t_pars_list **parser)
{
	*parser = malloc(sizeof(t_pars_list));
	if (!(*parser) || !parser)
		return (0);
	(*parser)->head = NULL;
	(*parser)->tail = NULL;
	return (1);
}

void	init_parsing_node(t_pars_node *node)
{
	node->content = NULL;
	node->nw_content = NULL;
	node->previous = NULL;
	node->type = 0;
	node->quote_or_not = 0;
	node->next = NULL;
}

t_pars_list	*list_end_parse(t_pars_list *list, char *content)
{
	t_pars_node	*node;

	if (!list || !content)
		return (NULL);
	node = malloc(sizeof(t_pars_node));
	if (!node)
		return (NULL);
	init_parsing_node(node);
	node->content = ft_strdup(content);
	node->next = NULL;
	if (list->tail == NULL)
	{
		node->previous = NULL;
		list->tail = node;
		list->head = node;
	}
	else
	{
		list->tail->next = node;
		node->previous = list->tail;
		list->tail = node;
	}
	list->length++;
	return (list);
}

void	display_parsing(t_pars_list *parser)
{
	t_pars_node	*i;

	i = parser->head;
	while (i)
	{
		printf("parsing = %s\n", i->content);
		printf("type = %u\n", i->type);
		i = i->next;
	}
}
