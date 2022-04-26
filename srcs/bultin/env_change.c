/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:46:26 by emtran            #+#    #+#             */
/*   Updated: 2022/04/25 11:13:23 by emtran           ###   ########.fr       */
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

void	create_node_to_export_or_env(t_env *node, t_env_list *list)
{
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
}

void	export_var_to_export(t_args *args, t_env_list *export, char *var, \
int check)
{
	t_env	*node;

	if (!export)
		return ;
	if (check_existing_var(export, var))
	{
		if (check == 2)
			return ;
		replace_existing_var_exp(args, export, var, check);
		return ;
	}
	node = NULL;
	node = malloc(sizeof(t_env));
	if (!node)
		intersection_of_errors(2, args);
	init_env_node(node);
	set_new_content_in_export(node, var, args, check);
	create_node_to_export_or_env(node, export);
	sort_export(export);
	export->length++;
}

void	export_var_to_env(t_args *args, t_env_list *env, char *var, int check)
{
	t_env	*node;

	if (!env)
		return ;
	if (check == 2)
		return ;
	if (check_existing_var(env, var))
	{
		replace_existing_var(args, env, var);
		return ;
	}
	node = NULL;
	node = malloc(sizeof(t_env));
	if (!node)
		intersection_of_errors(2, args);
	init_env_node(node);
	set_new_content_in_env(node, var, args);
	create_node_to_export_or_env(node, env);
	env->length++;
}
