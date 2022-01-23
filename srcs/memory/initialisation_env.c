/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:28:16 by emtran            #+#    #+#             */
/*   Updated: 2022/01/23 17:10:40 by emtran           ###   ########.fr       */
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
}