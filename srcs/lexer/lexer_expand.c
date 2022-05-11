/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:03:17 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/11 21:27:10 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*return_var(char *str, t_env_list *env, int datas[2])
{
	int		i;
	char	*var;
	char	*content;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			datas[0] += i;
			var = check_variable(&str, ft_strlen(str));
			datas[0] += ft_strlen(var);
			content = put_content_of_expand_sans_check(var, env);
			free(var);
			return (content);
		}
		i++;
		datas[0] += i;
	}
	return (NULL);
}

int	split_to_node(char *str, t_pars_list *list, t_pars_node *node, \
t_env_list *env)
{
	t_pars_node	*node2;
	char		**split;
	int			i;

	node2 = node;
	split = NULL;
	i = 0;
	split = ft_split(str, ' ');
	if (!split)
		return (-1);
	while (split[i])
	{
		list_mid_parse(list, node2, split[i]);
		expand(node2->content, node2, env);
		convert_content_without_quotes(node2->content, node2);
		encrypting(node2->content, node2);
		node2 = node2->next;
		if (i == 0)
			delete_pars_node(node2->previous);
		i++;
	}
	return (i - 1);
}

int	loop_var(char *str, t_pars_list *l, t_env_list *env, t_pars_node *node)
{
	int		datas[2];
	char	*var;
	char	*final;

	final = ft_strdup("");
	if (!str)
		return (-1);
	datas[0] = 0;
	datas[1] = 0;
	if (!is_charset('$', str))
		return (0);
	while (datas[0] < ft_strlen(str))
	{
		var = return_var(str + datas[0], env, datas);
		final = ft_strjoin(final, var);
		if (datas[0] == ft_strlen(str))
			break ;
	}
	return (split_to_node(final, l, node, env));
}

int	first_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (-1);
	return (0);
}

int	split_expand(t_pars_list *l, t_env_list *env)
{
	t_pars_node	*node;
	int			nodes_added;

	(void)env;
	nodes_added = 0;
	node = l->head;
	if (!node)
		return (-1);
	while (node)
	{
		if (!quotes_or_not(node->content) && is_charset('$', node->content))
		{
			loop_var(node->content, l, env, node);
		}
		node = node->next;
	}
	return (nodes_added);
}
