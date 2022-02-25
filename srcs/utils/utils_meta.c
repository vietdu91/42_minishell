/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:25:18 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/11 14:46:18 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_full_meta(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (str[++i])
	{
		if (!is_meta(str[i]))
			return (0);
	}
	return (1);
}

char	*new_content_first(t_pars_node *node, int *i)
{
	int		size;
	char	*first;

	if (node->content[1] && node->content[0] == node->content[1])
		size = 3;
	else
		size = 2;
	first = malloc(sizeof(char) * size);
	while (++(*i) < size - 1)
		first[*i] = node->content[*i];
	first[*i] = 0;
	return (first);
}

void	splitter_content_meta(t_pars_node *node, t_pars_list *l)
{
	int		i;
	char	*first;
	int		len;

	i = -1;
	first = new_content_first(node, &i);
	len = ft_strlen(first);
	add_node_after_current(node->content + len, node, l);
	free(node->content);
	node->content = first;
}

int	does_meta_exist(t_pars_node *node)
{
	if (!ft_strcmp(node->content, "<"))
		return (1);
	else if (!ft_strcmp(node->content, "<<"))
		return (1);
	else if (!ft_strcmp(node->content, ">"))
		return (1);
	else if (!ft_strcmp(node->content, ">>"))
		return (1);
	else if (!ft_strcmp(node->content, "|"))
		return (1);
	else if (!ft_strcmp(node->content, "||"))
		return (1);
	else if (!ft_strcmp(node->content, "&&"))
		return (1);
	else if (!ft_strcmp(node->content, "*"))
		return (1);
	else if (!ft_strcmp(node->content, ";"))
		return (1);
	return (0);
}
