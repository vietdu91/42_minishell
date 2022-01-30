/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:53:10 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/30 20:46:14 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	init_parsing_list(t_parsing_list **l)
{
	*l = malloc(sizeof(t_parsing_list));
	if (!(*l) || !l)
		return (0);
	(*l)->head = NULL;
	(*l)->tail = NULL;
	return (1);
}

void	init_parsing_node(t_parsing_node *node)
{
	node->content = NULL;
	node->arg = 0;
	node->cmd = 0;
	node->file = 0;
	node->builtin = 0;
	node->previous = NULL;
	node->next = NULL;
}

t_parsing_list	*list_end_parse(t_parsing_list *list, char *content)
{
	t_parsing_node	*node;

	if (!list || !content)
		return (NULL);
	node = malloc(sizeof(t_parsing_node));
	if (!node)
		return (NULL);
	printf("yo\n");
	init_parsing_node(node);
	node->content = content;
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

void	display_parsing(t_parsing_list *l)
{
	t_parsing_node	*i;

	i = l->head;
	while (i)
	{
		printf("parsing = %s\n", i->content);
		i = i->next;
	}
}
