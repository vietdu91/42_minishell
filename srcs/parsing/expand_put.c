/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:28:37 by emtran            #+#    #+#             */
/*   Updated: 2022/02/14 17:37:08 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	put_content_exp_sans_q(t_pars_node *node, int *i, int *j, char quote)
{
	(*i)++;
	while (node->content_exp[*i] && node->content_exp[*i] != quote)
		node->content_exp_sans_q[(*j)++] = node->content_exp[(*i)++];
	(*i)++;
}

char	*put_content_of_expand(char *var, t_env_list *env)
{
	t_env	*node;
	char	*content;

	node = NULL;
	node = env->head;
	content = NULL;
	while (node)
	{
		if (!ft_strcmp(var, "$"))
			return ("$");
		if (!ft_strcmp(var, "?"))
			return (ft_itoa(g_exit_status));
		if (!ft_strcmp(var, node->variable))
		{
			content = ft_strdup(node->content);
			return (content);
		}
		node = node->next;
	}
	return ("");
}
