/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:28:37 by emtran            #+#    #+#             */
/*   Updated: 2022/02/24 10:33:43 by emtran           ###   ########.fr       */
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

char	*check_put_content_of_expand(char *var, char *content, t_env *node)
{
	if (!ft_strcmp(var, "$"))
	{
		content = ft_strdup("$");
		return (content);
	}
	else if (!ft_strcmp(var, "?"))
	{
		content = ft_itoa(g_exit_status);
		return (content);
	}
	else if (!ft_strcmp(var, node->variable))
	{
		content = ft_strdup(node->content);
		return (content);
	}
	return (NULL);
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
		content = check_put_content_of_expand(var, content, node);
		if (content)
			return (content);
		node = node->next;
	}
	content = ft_strdup("");
	return (content);
}
