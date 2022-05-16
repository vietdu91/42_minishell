/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc_norm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 20:20:00 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 20:26:55 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*size_and_malloc(char **d_tab)
{
	char	*string;
	int		i;
	int		j;
	int		k;

	string = NULL;
	i = -1;
	k = 0;
	while (d_tab[++i])
	{
		j = 0;
		while (d_tab[i][j++])
			k++;
	}
	string = malloc(sizeof(char) * (k + 1));
	if (!string)
		return (NULL);
	return (string);
}
