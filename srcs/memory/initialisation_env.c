/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:28:16 by emtran            #+#    #+#             */
/*   Updated: 2022/03/04 13:39:44 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env_list	*init_env_list(t_env_list *env, t_args *args)
{
	env = NULL;
	env = (t_env_list *)malloc(sizeof(t_env_list));
	if (!env)
		intersection_of_errors(2, args);
	env->head = NULL;
	env->tail = NULL;
	env->length = 0;
	return (env);
}

void	init_env_node(t_env *node)
{
	node->next = NULL;
	node->line = NULL;
	node->variable = NULL;
	node->content = NULL;
	node->len_content = 0;
	node->var_id = 0;
}

void	reset_env_node(t_env *node)
{
	node->line = NULL;
	node->variable = NULL;
	node->content = NULL;
	node->len_content = 0;
	node->var_id = 0;
}
