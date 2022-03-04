/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:35:49 by emtran            #+#    #+#             */
/*   Updated: 2022/03/04 16:04:31 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	node->len_content = ft_strlen(node->content);
}

void	set_new_content_in_export(t_env *node, char *content, t_args *args, \
int check)
{
	node->line = ft_strdup(content);
	if (!node->line)
		intersection_of_errors(2, args);
	node->variable = set_variable_env(node->line);
	if (!node->variable)
		intersection_of_errors(2, args);
	if (check == 1)
	{
		node->content = set_content_env(node->line);
		if (!node->content)
			intersection_of_errors(2, args);
	}
	node->var_id = set_id_env(node->variable);
	node->len_content = ft_strlen(node->content);
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
	if (!ft_strcmp(str, "PWD"))
		return (PWD);
	else if (!ft_strcmp(str, "OLDPWD"))
		return (OLDPWD);
	else if (!ft_strcmp(str, "HOME"))
		return (HOME);
	else if (!ft_strcmp(str, "SHLVL"))
		return (SHLVL);
	else
		return (BASIC);
}
