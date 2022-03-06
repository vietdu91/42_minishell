/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_is_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 15:04:31 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/05 20:45:03 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

int	cmd_is_path(char *array, t_pars_node *c)
{
	char	*no_space;

	no_space = NULL;
	no_space = cut_path(array, no_space);
	if (!no_space)
		return (0);
	if (access(no_space, F_OK) == 0 && \
		(no_space[0] == '/' || no_space[0] == '.'))
	{
		c->path = ft_strdup(array);
		free(no_space);
		return (1);
	}
	free(no_space);
	return (0);
}