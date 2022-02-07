/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:14:40 by emtran            #+#    #+#             */
/*   Updated: 2022/02/07 16:45:51 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_len_word_in_quotes(char quote, char *str, int *pos, int count)
{
	(*pos)++;
	count++;
	while (str[*pos] != quote)
	{
		(*pos)++;
		count++;
	}
	(*pos)++;
	count++;
	return (count);
}

void	cpy_with_double_quotes(size_t *i, size_t *j, char *dest, char *src)
{
	if (src[*i] && src[*i] == '\"')
	{	
		(*i)++;
		while (src[*i] && src[*i] != '\"')
		{
			dest[(*j)++] = src[(*i)++];
		}
		(*i)++;
	}
	else if (src[*i] && src[*i] == '\'')
	{	
		(*i)++;
		while (src[*i] && src[*i] != '\'')
		{
			dest[(*j)++] = src[(*i)++];
		}
		(*i)++;
	}
	else
		dest[(*j)++] = src[(*i)++];
}

int	count_words_with_quotes(char *s, int *count, int i, char quote)
{
	(*count)++;
	i++;
	while (s[i] != quote && s[i])
		i++;
	i++;
	return (i);
}

int	size_word_with_quotes(char *s, t_args *args, char quote)
{
	int	count;

	count = 0;
	s++;
	args->quote_parse = 2;
	while (*s && *s != quote)
	{
		count++;
		s++;
	}
	s++;
	return (count);
}