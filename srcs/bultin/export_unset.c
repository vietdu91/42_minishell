/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:32 by emtran            #+#    #+#             */
/*   Updated: 2022/01/27 14:39:39 by emtran           ###   ########.fr       */
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
	g_exit_status = 0;
}
