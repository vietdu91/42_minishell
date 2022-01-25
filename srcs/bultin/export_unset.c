/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:32 by emtran            #+#    #+#             */
/*   Updated: 2022/01/25 18:49:07 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_export(t_args *args)
{
	t_env	*node_env;

	if (!args)
		return ;
	node_env = NULL;
	node_env = args->env->head;
	while (node_env)
	{
		set_var_to_export(args->export, node_env, args);
		node_env = node_env->next;
	}
	sort_export(args->export);
	display_export(args->export);
}
