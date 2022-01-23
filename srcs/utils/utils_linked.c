/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_linked.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:34:19 by emtran            #+#    #+#             */
/*   Updated: 2022/01/23 13:57:37 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*init_list(void)
{
	t_list	*list;

	list = NULL;
	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;
	return (list);
}

t_list	*list_end(t_list *list, char *content)
{
	t_node	*node;

	if (!list || !content)
		return (NULL);
	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->content = ft_strdup(content);
	if (!node->content)
		return (NULL);
	node->next = NULL;
	if (list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}
	list->length++;
	return (list);
}

void	list_display(t_list *l)
{
	t_node	*i;

	i = l->head;
	while (i)
	{
		printf("%s\n", i->content);
		i = i->next;
	}
}