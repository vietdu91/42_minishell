/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:59:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/23 17:13:26 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_variable_env(char *str)
{
	int		i;
	char	*variable;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	variable = malloc(sizeof(char) * (i + 1));
	if (!variable)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		variable[i] = str[i];
		i++;
	}
	variable[i] = 0;
	return (variable);
}

char	*get_content_env(char *str)
{
	int		i;
	int		j;
	char	*content;

	i = ft_strlen(str) - 1;
	j = 0;
	while (str[i] && str[i] != '=')
		i--;
	content = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!content)
		return (NULL);
	while (str[++i])
	{
		content[j++] = str[i];
	}
	content[j] = 0;
	return (content);
}

t_env_list	*add_var_to_env(t_env_list *env, char *content, t_args *args)
{
	t_env	*node;

	if (!args)
		return (NULL);
	node = malloc(sizeof(t_node));
	if (!node)
		intersection_of_errors(2, args);
	node->line = ft_strdup(content);
	node->variable = get_variable_env(node->line);
	node->content = get_content_env(node->line);
	if (!node->line)
		intersection_of_errors(2, args);
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

	if (!args || !args->env)
		return ;
	current = NULL;
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
		intersection_of_errors(1, args);
	args->env = init_env_list(args);
	while (envp[i])
	{
		add_var_to_env(args->env, envp[i], args);
		i++;
	}
}
