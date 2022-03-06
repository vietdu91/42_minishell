/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:53:10 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/06 17:43:45 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	init_parsing_list(t_pars_list **parser)
{
	*parser = malloc(sizeof(t_pars_list));
	if (!(*parser) || !parser)
		return (0);
	(*parser)->head = NULL;
	(*parser)->tail = NULL;
	(*parser)->length = 0;
	return (1);
}

void	init_parsing_node(t_pars_node *node)
{
	node->content = NULL;
	node->nw_content = NULL;
	node->content_exp = NULL;
	node->content_exp_sans_q = NULL;
	node->previous = NULL;
	node->type = 0;
	node->next = NULL;
	node->index_crypted = 0;
	node->path = NULL;
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
		if (i->type == CMD)
			printf("Path = %s\n", i->path);
		printf("parsing = %s\n", i->content);
		printf("content_exp = %s\n", i->content_exp);
		printf("content_exp_sans_quotes = %s\n", i->content_exp_sans_q);
		printf("nw_content = %s\n", i->nw_content);
		printf("type = %u\n\n", i->type);
		i = i->next;
	}
}
