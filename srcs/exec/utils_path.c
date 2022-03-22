/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 16:28:08 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/22 12:59:45 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_slash(char **to_try)
{
	int	i;
	int	end;

	i = -1;
	while (to_try[++i])
	{
		end = ft_strlen(to_try[i]);
		if (to_try[i][end - 1] != '/')
			to_try[i] = ft_strjoin(to_try[i], "/");
	}
}

int	add_cmd(char **to_try, char *cmd)
{
	int		i;
	// char	**av;

//	printf("cmd add cmd = %s\n", cmd);
	// av = ft_split(cmd, ' ');
	// if (!av)
	// 	return (0);
	i = -1;
	while (to_try[++i])
	{
		to_try[i] = ft_strjoin(to_try[i], cmd);
		if (!to_try[i])
			return (0);
	}
	// free_d_tab(av);
	return (1);
}
