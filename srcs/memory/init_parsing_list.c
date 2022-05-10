/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 19:53:10 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/06 14:35:44 by emtran           ###   ########.fr       */
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
	(*parser)->pipe[0] = 0;
	(*parser)->pipe[1] = 0;
	return (1);
}

void	init_parsing_node(t_pars_node *node)
{
	node->content = NULL;
	node->nw_content = NULL;
	node->content_exp = NULL;
	node->content_exp_sans_q = NULL;
	node->type = 0;
	node->check_in = FALSE;
	node->len = 0;
	node->index_crypted = 0;
	node->cmds = NULL;
	node->path = NULL;
	node->fds[0] = 0;
	node->fds[1] = 0;
	node->previous = NULL;
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
	node->len = list->length;
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

t_pars_list	*list_mid_parse(t_pars_list *list, t_pars_node *n, char *content)
{
	t_pars_node	*node;

	if (!list || !n || !content)
		return (NULL);
	node = malloc(sizeof(t_pars_node));
	if (!node)
		return (NULL);
	init_parsing_node(node);
	node->content = ft_strdup(content);
	if (n->next == NULL)
	{
		node->next = NULL;
		list->tail = node;
	}
	else
	{
		n->next->previous = node;
		if (n->next)
			node->next = n->next;
	}
	n->next = node;
	node->previous = n;
	list->length++;
	return (list);
}

void	display_parsing(t_pars_list *parser)
{
	t_pars_node	*i;
	int			j;

	j = -1;
	i = parser->head;
	while (i)
	{
		if (i->type == CMD)
		{
			printf("Path = %s\n", i->path);
			while (i->cmds[++j])
				printf("%s\n", i->cmds[j]);
		}
		printf("parsing = %s\n", i->content);
		printf("len->content = %d\n", ft_strlen(i->content));
		printf("id_node = %d\n", i->len);
		printf("content_exp = %s\n", i->content_exp);
		printf("content_exp_sans_quotes = %s\n", i->content_exp_sans_q);
		printf("nw_content = %s\n", i->nw_content);
		printf("type = %u\n\n", i->type);
		i = i->next;
	}
}
