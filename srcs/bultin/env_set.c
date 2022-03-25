/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 13:35:49 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 14:55:57 by dyoula           ###   ########.fr       */
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
	node->content_trim = set_content_trim_env(node->content, ' ');
	node->content_trim = remove_interior_spaces(node->content_trim);
	if (!node->content_trim)
		intersection_of_errors(2, args);
	node->var_id = set_id_env(node->variable);
	node->len_content = ft_strlen(node->content);
}

char	*set_content_trim_env(char *str, char trim)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	if (!str || !trim)
		return (NULL);
	if (str[i] == '\0')
		return (ft_strdup(""));
	while (str[i] && str[i] == trim)
		i++;
	j = ft_strlen(str) - 1;
	if (i == j)
		len = 0;
	else
	{
		while (j >= i && str[j] == trim)
			j--;
		len = j - i + 1;
	}
	i = 0;
	while (str[i] && str[i] == trim)
		i++;
	return (ft_substr(str, i, len));
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

	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		i++;
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
