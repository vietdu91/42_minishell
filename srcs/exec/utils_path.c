/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:28:08 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/21 11:28:05 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_slash(char **to_try)
{
	int	i;
	int	j;

	i = -1;
	while (to_try[++i])
	{
		j = 0;
		while (to_try[i][j])
			j++;
		j--;
		if (to_try[i][j] != '/')
			to_try[i] = ft_strjoin(to_try[i], "/");
	}
}

/* char	**av;

	printf("cmd add cmd = %s\n", cmd);
	av = ft_split(cmd, ' ');
	if (!av)
	return (0);
	
	free_d_tab(av);*/

int	add_cmd(char **to_try, char *cmd)
{
	int		i;

	i = -1;
	while (to_try[++i])
	{
		to_try[i] = ft_strjoin(to_try[i], cmd);
		if (!to_try[i])
			return (0);
	}
	return (1);
}
