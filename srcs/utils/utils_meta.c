/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_meta.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:25:18 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/08 00:18:01 by dyoula           ###   ########.fr       */
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
		j = -1;
		while (METACHAR[++j])
			if (str[i] != METACHAR[j])
				return (0);
	}
	return (1);
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
