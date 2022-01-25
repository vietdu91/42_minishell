/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:59:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/25 15:28:03 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_new_content_in_env(t_env *node, char *content, t_args *args)
{
	node->line = ft_strdup(content);
	if (!node->line)
		intersection_of_errors(2, args);
	node->variable = set_variable_env(node->line);
	if (!node->variable)
		intersection_of_errors(2, args);
	node->content = set_content_env(node->line);
	if (!node->content)
		intersection_of_errors(2, args);
	node->var_id = set_id_env(node->variable);
}

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

void	display_env(t_env_list *env)
{
	t_env	*current;

	if (!env)
		return ;
	current = NULL;
	current = env->head;
	while (current)
	{
		printf("%s\n", current->line);
		current = current->next;
	}
}

void	get_env(t_args *args, char **envp)
{
	int	i;

	i = 0;
	args->export = init_env_list(args->export, args);
	args->env = init_env_list(args->env, args);
	while (envp[i])
	{
		add_var_to_env(args->env, envp[i], args);
		i++;
	}
	g_exit_status = 0;
}
