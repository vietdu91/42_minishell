/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_what_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:38:39 by emtran            #+#    #+#             */
/*   Updated: 2022/01/03 15:00:14 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_alpha(char c)
{
	int			a;
	const char	*lower = LOW_ALPHA;
	const char	*upper = UPP_ALPHA;

	a = 0;
	while (lower[a] != '\0' || upper[a] != '\0')
	{
		if (lower[a] == c)
			return (1);
		if (upper[a] == c)
			return (1);
		a++;
	}
	return (0);
}

int	is_upper(char c)
{
	int			a;
	const char	*upper = UPP_ALPHA;

	a = -1;
	while (upper[++a] != '\0')
	{
		if (upper[a] == c)
			return (1);
	}
	return (0);
}

int	is_lower(char c)
{
	int			a;
	const char	*lower = LOW_ALPHA;

	a = -1;
	while (lower[++a] != '\0')
	{
		if (lower[a] == c)
			return (1);
	}
	return (0);
}

int	is_alphanum(char c)
{
	if (!is_alpha(c) && !is_digit(c))
		return (0);
	return (1);
}
