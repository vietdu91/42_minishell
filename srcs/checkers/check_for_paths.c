/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:49:08 by emtran            #+#    #+#             */
/*   Updated: 2022/05/08 19:51:15 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_special(char c)
{
	int			a;
	const char	*str = SPECIAL;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}

int	is_a_directory(char *str)
{
	DIR	*fd;

	fd = opendir(str);
	if (fd || errno == 13)
	{
		if (fd)
			closedir(fd);
		return (1);
	}
	return (0);
}

int	is_a_special_directory(char *str)
{
	int	ret;

	ret = 0;
	ret = chdir(str);
	if (!ret)
		return (1);
	return (0);
}
