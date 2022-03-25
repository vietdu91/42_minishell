/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:38:42 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 14:58:12 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_existing_var(t_env_list *env, char *var)
{
	t_env	*node;
	char	*variable;

	node = NULL;
	node = env->head;
	variable = set_variable_env(var);
	while (node)
	{
		if (!ft_strcmp(variable, node->variable))
		{
			free(variable);
			return (1);
		}
		node = node->next;
	}
	free(variable);
	return (0);
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
		node->content_trim = set_content_trim_env(node->content, ' ');
		if (!node->content_trim)
			intersection_of_errors(2, args);
	}
	node->var_id = set_id_env(node->variable);
	node->len_content = ft_strlen(node->content);
}

void	replace_existing_var(t_args *args, t_env_list *env, char *var)
{
	t_env	*node;
	char	*variable;

	node = NULL;
	node = env->head;
	variable = set_variable_env(var);
	while (node)
	{
		if (!ft_strcmp(variable, node->variable))
		{
			free_content_env_node(node);
			reset_env_node(node);
			set_new_content_in_env(node, var, args);
		}
		node = node->next;
	}
	free(variable);
}

void	replace_existing_var_exp(t_args *args, t_env_list *export, char *var, \
int check)
{
	t_env	*node;
	char	*variable;

	node = NULL;
	node = export->head;
	variable = set_variable_env(var);
	while (node)
	{
		if (!ft_strcmp(variable, node->variable))
		{
			free_content_env_node(node);
			reset_env_node(node);
			set_new_content_in_export(node, var, args, check);
		}
		node = node->next;
	}
	free(variable);
}
