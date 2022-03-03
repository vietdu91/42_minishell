/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:32 by emtran            #+#    #+#             */
/*   Updated: 2022/03/03 16:43:35 by emtran           ###   ########.fr       */
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

int	check_id_export(char *str)
{
	int	i;

	i = 0;
	if (is_digit(str[i]))
		return (1);
	else if (str[i] == '\0')
		return (0);
	else if (!is_alphanum(str[i]) && str[i] != '_')
		return (1);
	i++;
	while (str[i] != '=')
	{
		if (!is_alphanum(str[i]) && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	export_main(t_args *args, t_env_list *env, t_env_list *export, \
t_pars_node *parser)
{
	t_pars_node	*node;

	(void) args;
	(void) env;
	node = parser->next;
	if (!node)
	{
		display_export(export);
		return ;
	}
	while (node)
	{
		if (node->type == 20)
			invalid_option(node, CMD_UNSET);
		else if (check_id_export(node->content_exp_sans_q))
		{
			print_error_w_quote(BASH, CMD_EXPORT, node->content_exp_sans_q, \
			ERR_ID);
			g_exit_status = 1;
		}
		node = node->next;
	}
}
