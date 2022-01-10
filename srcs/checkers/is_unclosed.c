/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unclosed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:55:41 by emtran            #+#    #+#             */
/*   Updated: 2022/01/10 14:26:46 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_unclosed_quotes(char *str)
{
	int	i;
	int	nb_single_q;
	int	nb_double_q;

	i = -1;
	nb_single_q = 0;
	nb_double_q = 0;
	while (str[++i])
	{
		if (str[i] == '\'')
			nb_single_q++;
		if (str[i] == '\"')
			nb_double_q++;
	}
	if (nb_single_q % 2 != 0 || nb_double_q % 2 != 0)
		return (1);
	return (0);
}

int	is_unclosed_parenth(char *str)
{
	int	i;
	int	parenth_open;
	int	parenth_close;

	i = -1;
	parenth_open = 0;
	parenth_close = 0;
	while (str[++i] != '(')
	{
		if (str[i] == ')')
			return (1);
	}
	while (str[i])
	{
		if (str[i] == '(')
			parenth_open++;
		if (str[i] == ')')
			parenth_close++;
		i++;
	}
	if (parenth_open != parenth_close)
		return (1);
	return (0);
}
