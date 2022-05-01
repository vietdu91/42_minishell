/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:34:31 by emtran            #+#    #+#             */
/*   Updated: 2022/04/28 11:00:48 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_the_len_of_variable(int *count, int *i, char *str)
{
	if (str[*i + 1] == '$' || str[*i + 1] == '\0' || is_quote(str[*i + 1]) \
	|| (!is_alphanum(str[*i + 1]) && str[*i + 1] != '_'))
	{
		(*count)++;
		if (str[*i + 1] != '\0')
		{
			if (is_quote(str[*i + 2]))
				(*count)++;
		}
		return ;
	}
	(*i)++;
	if (is_digit(str[*i]) || str[*i] == '?')
	{
		(*count)++;
		return ;
	}
	while (is_alphanum(str[*i]) || str[*i] == '_')
	{
		(*i)++;
		(*count)++;
	}
}

int	len_of_variable(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			count_the_len_of_variable(&count, &i, str);
			break ;
		}
		else
			i++;
	}
	return (count);
}

void	found_variable(char **str)
{
	if (*(*str + 1) == '?')
		(*str)++;
	else if (*(*str + 1) != '$' && ft_strcmp("$", *str) \
	&& !is_quote(*(*str + 1)) && ((is_alphanum(*(*str + 1)) == 1)
	|| *(*str + 1) == '_'))
		(*str)++;
	else if (is_quote(*(*str + 1)) && is_quote(*(*str + 2)))
		(*str)++;
}

char	*check_variable(char **str, int len)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	j = 0;
	var = NULL;
	while (**str && *str && j++ < len)
	{
		if (**str == '$')
		{
			i = len_of_variable(*str);
			found_variable(str);
			var = malloc(sizeof(char) * (i + 1));
			ft_strncpy(var, *str, i);
			while (i-- > 0)
				(*str)++;
			return (var);
		}
	}
	return (var);
}
