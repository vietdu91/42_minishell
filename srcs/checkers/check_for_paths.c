/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_paths.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:49:08 by emtran            #+#    #+#             */
/*   Updated: 2022/04/25 15:19:48 by emtran           ###   ########.fr       */
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
	int	a;

	a = -1;
	// printf("STR : %s\n", str);
	if (str[0] == '\0')
		return (0);
	while (str[++a] != '\0')
	{
		if (str[a] != '.' && str[a] != '/')
			return (0);
	}
	return (1);
}
