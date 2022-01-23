/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:59:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/23 16:29:20 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env_list	*add_var_to_env(t_env_list *env, char *content, t_args *args)
{
	t_env	*node;

	if (!args)
		return (NULL);
	node = malloc(sizeof(t_node));
	if (!node)
		fork_of_errors(2, args);
	node->line = ft_strdup(content);
	if (!node->line)
		fork_of_errors(2, args);
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

void	display_env(t_args *args)
{
	t_env	*current;

	current = NULL;
	if (!args || !args->env)
		return ;
	current = args->env->head;
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
	if (!envp)
		fork_of_errors(1, args);
	args->env = init_env_list(args);
	while (envp[i])
	{
		add_var_to_env(args->env, envp[i], args);
		i++;
	}
}
