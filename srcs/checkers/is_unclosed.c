/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unclosed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:55:41 by emtran            #+#    #+#             */
/*   Updated: 2022/02/17 16:14:48 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_unclosed(t_args *args)
{
	int	checker;

	checker = is_unclosed_quotes(args->buffer);
	if (checker > 0)
	{
		if (checker == 1)
			print_syntax_error(ERR_UNCLOSED, "'");
		else if (checker == 2)
			print_syntax_error(ERR_UNCLOSED, "\"");
		g_exit_status = 2;
		return (1);
	}
	return (0);
}

int	is_unclosed_quotes(char *str)
{
	int		i;
	int		status_quote;

	i = 0;
	status_quote = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			if (status_quote == 0)
				status_quote = 1;
			else if (status_quote == 1)
				status_quote = 0;
		}
		if (str[i] == '"')
		{
			if (status_quote == 0)
				status_quote = 2;
			else if (status_quote == 2)
				status_quote = 0;
		}
		i++;
	}
	return (status_quote);
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
