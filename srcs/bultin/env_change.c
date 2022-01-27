/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:46:26 by emtran            #+#    #+#             */
/*   Updated: 2022/01/27 19:11:30 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env_list	*add_var_to_env(t_env_list *env, char *content, t_args *args)
{
	t_env	*node;

	if (!args)
		return (NULL);
	node = NULL;
	node = malloc(sizeof(t_env));
	if (!node)
		intersection_of_errors(2, args);
	init_env_node(node);
	set_new_content_in_env(node, content, args);
	if (env->head == NULL)
	{
		env->head = node;
		env->tail = node;
	}
	else
	{
		env->tail->next = node;
		env->tail = node;
	}
	env->length++;
	return (env);
}
/*
t_env_list	*del_var_from_env(t_env_list *env, char *content, t_args *args)
{
	t_env	*node;
	t_env   

	if (!args)
		return (NULL);
	node = NULL;
	node = env->head;
	while
}*/