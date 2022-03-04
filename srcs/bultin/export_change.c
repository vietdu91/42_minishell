/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_change.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:38:42 by emtran            #+#    #+#             */
/*   Updated: 2022/03/04 16:05:19 by emtran           ###   ########.fr       */
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

void	replace_existing_var_exp(t_args *args, t_env_list *export, char *var, int check)
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
