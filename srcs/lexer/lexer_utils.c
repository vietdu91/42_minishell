/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:50:38 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/10 19:26:35 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*cut_path(char *str, char *no_space)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] <= 9 || str[i] >= 13) && str[i] != ' ')
		i++;
	no_space = malloc(sizeof(char) * (i + 1));
	if (!no_space && no_space)
		return (NULL);
	while (j < i)
	{
		no_space[j] = str[j];
		j++;
	}
	no_space[j] = 0;
	return (no_space);
}

int	check_enum(int n)
{
	const int	meta[] = {11, 13, 15, 17};
	int			i;

	i = -1;
	while (++i < 4)
		if (meta[i] == n)
			return (1);
	return (0);
}

void	norm_heredoc(t_pars_node *node)
{
	if (!node)
		return ;
	if (!node->next)
		return ;
	node->next->type = LIMITATOR;
	if (!node->next->next)
		return ;
	node->next->next->type = CMD;
}
