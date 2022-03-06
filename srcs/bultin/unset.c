/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:12:23 by emtran            #+#    #+#             */
/*   Updated: 2022/03/03 10:57:37 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_env	*find_previous_node(t_env_list *env, char *var)
{
	t_env	*node;
	t_env	*tmp;

	node = NULL;
	tmp = NULL;
	node = env->head;
	while (node)
	{
		tmp = node;
		node = node->next;
		if (!ft_strcmp(node->variable, var))
			return (tmp);
	}
	return (NULL);
}

void	delete_var_list(t_env_list *env, char *var)
{
	t_env	*node;
	t_env	*previous;

	node = NULL;
	node = env->head;
	previous = find_previous_node(env, var);
	while (node)
	{
		if (!ft_strcmp(node->variable, var))
		{
			if (!previous)
			{
				env->head = env->head->next;
				free_env_node(node);
				return ;
			}
			node = previous->next;
			previous->next = previous->next->next;
			free_env_node(node);
			return ;
		}
		node = node->next;
	}
}

int	check_id_unset(char *str)
{
	int	i;

	i = 0;
	if (is_digit(str[i]))
		return (1);
	else if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (!is_alphanum(str[i]) && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	unset_main(t_args *args, t_pars_node *parser)
{
	t_pars_node	*node;

	node = parser->next;
	while (node)
	{
		if (node->type == 20)
			invalid_option(node, CMD_UNSET);
		else if (check_id_unset(node->content_exp_sans_q))
		{
			print_error_w_quote(BASH, CMD_UNSET, node->content_exp_sans_q, \
			ERR_ID);
			g_exit_status = 1;
		}
		else
		{
			delete_var_list(args->env, node->content_exp_sans_q);
			delete_var_list(args->export, node->content_exp_sans_q);
		}
		node = node->next;
	}
}
