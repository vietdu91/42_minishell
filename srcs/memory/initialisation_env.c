/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:28:16 by emtran            #+#    #+#             */
/*   Updated: 2022/01/24 14:20:49 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_list	*init_env_list(t_args *args)
{
	args->env = NULL;
	args->env = (t_env_list *)malloc(sizeof(t_env_list));
	if (!args->env)
		intersection_of_errors(2, args);
	args->env->head = NULL;
	args->env->tail = NULL;
	args->env->length = 0;
	return (args->env);
}

void	init_env_node(t_env *node)
{
	node->next = NULL;
	node->line = NULL;
	node->variable = NULL;
	node->content = NULL;
	node->var_id = 0;
}

char	*set_variable_env(char *str)
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

char	*set_content_env(char *str)
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

int	set_id_env(char *str)
{
	if (ft_strcmp(str, "PWD"))
		return (PWD);
	else if (ft_strcmp(str, "OLDPWD"))
		return (OLDPWD);
	else if (ft_strcmp(str, "HOME"))
		return (HOME);
	else if (ft_strcmp(str, "SHLVL"))
		return (SHLVL);
	else
		return (BASIC);
}