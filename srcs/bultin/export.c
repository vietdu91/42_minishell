/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:32 by emtran            #+#    #+#             */
/*   Updated: 2022/04/26 18:35:10 by emtran           ###   ########.fr       */
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
		return (0);
	else if (!ft_strcmp(str, ""))
		return (0);
	else if (str[i] == '\0')
		return (1);
	else if (!is_alpha(str[i]) && str[i] != '_')
		return (0);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!is_alphanum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	if (str[i] == '\0')
		return (2);
	return (1);
}

void	bad_id_export(t_pars_node *node)
{
	print_error_w_quote(BASH, CMD_EXPORT, node->content_exp_sans_q, \
	ERR_ID);
	g_exit_status = 1;
}

void	export_main(t_args *args, t_env_list *env, t_env_list *export, \
t_pars_node *parser)
{
	t_pars_node	*node;
	int			check;
	bool		error;

	check = 0;
	error = FALSE;
	node = parser->next;
	if (!node || (node->type != SIMPLE_ARG && node->type != OPTION))
	{
		display_export(export);
		g_exit_status = 0;
		return ;
	}
	while (node)
	{
		check = check_id_export(node->content_exp_sans_q);
		if (node->type == OPTION)
		{
			invalid_option(node, CMD_UNSET);
			return ;
		}
		else if (!check)
		{
			bad_id_export(node);
			error = TRUE;
			g_exit_status = 1;
		}
		else
		{
			export_var_to_export(args, export, node->content_exp_sans_q, check);
			if (check == 1)
				export_var_to_env(args, env, node->content_exp_sans_q, check);
		}
		node = node->next;
	}
	if (error == FALSE)
		g_exit_status = 0;
}
