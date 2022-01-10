/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_others.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 14:42:38 by emtran            #+#    #+#             */
/*   Updated: 2022/01/10 14:27:40 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_digit(char c)
{
	int			a;
	const char	*str = DIGITS;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}

int	is_space(char c)
{
	int			a;
	const char	*str = SPACES;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}

int	is_meta(char c)
{
	int			a;
	const char	*str = METACHAR;

	a = -1;
	while (str[++a] != '\0')
	{
		if (str[a] == c)
			return (1);
	}
	return (0);
}

int	is_quote(char c)
{
	int		a;

	a = -1;
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}