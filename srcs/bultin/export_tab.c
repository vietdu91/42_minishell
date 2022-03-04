/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:43:05 by emtran            #+#    #+#             */
/*   Updated: 2022/03/04 15:34:09 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_node_export(t_env *node, t_env *env, t_args *args)
{
	node->line = ft_strdup(env->line);
	if (!node->line)
		intersection_of_errors(2, args);
	node->variable = ft_strdup(env->variable);
	if (!node->variable)
		intersection_of_errors(2, args);
	node->content = ft_strdup(env->content);
	if (!node->content)
		intersection_of_errors(2, args);
	node->var_id = env->var_id;
}

t_env_list	*set_var_to_export(t_env_list *export, t_env *env, t_args *args)
{
	t_env	*node;

	if (!args)
		return (NULL);
	node = NULL;
	node = malloc(sizeof(t_env));
	if (!node)
		intersection_of_errors(2, args);
	init_env_node(node);
	set_node_export(node, env, args);
	if (export->head == NULL)
	{
		export->head = node;
		export->tail = node;
	}
	else
	{
		export->tail->next = node;
		export->tail = node;
	}
	export->length++;
	return (export);
}

void	swap_export(t_env *node, t_env *node2)
{
	char	*swap;
	int		swip;

	swap = node->line;
	node->line = node2->line;
	node2->line = swap;
	swap = node->variable;
	node->variable = node2->variable;
	node2->variable = swap;
	swap = node->content;
	node->content = node2->content;
	node2->content = swap;
	swip = node->var_id;
	node->var_id = node2->var_id;
	node2->var_id = swip;
}

void	sort_export(t_env_list *export)
{
	t_env	*node;
	t_env	*node2;

	node = NULL;
	node2 = NULL;
	node = export->head;
	while (node)
	{
		node2 = export->head;
		while (node2)
		{
			if (ft_strcmp(node->variable, node2->variable) == -1)
				swap_export(node, node2);
			node2 = node2->next;
		}
		node = node->next;
	}
}

void	display_export(t_env_list *export)
{
	t_env	*current;

	if (!export)
		return ;
	current = NULL;
	current = export->head;
	while (current)
	{
		printf("export %s", current->variable);
		if (current->content)
		{
			if (ft_strcmp(current->content, "\0"))
				printf("=\"%s\"", current->content);
		}
		printf("\n");
		current = current->next;
	}
}
