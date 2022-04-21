/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:14:40 by emtran            #+#    #+#             */
/*   Updated: 2022/04/21 18:44:40 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_meta_in_quotes(char *str)
{
	int	i;
	int	quotes;
	int	encrypt;

	i = -1;
	quotes = 0;
	encrypt = 0;
	while (str[++i])
	{
		if (str[i] == '\"' && quotes == 0)
			quotes++;
		else if (str[i] == '\"' && quotes == 1)
			quotes--;
		if (is_meta(str[i]) && quotes == 1)
			encrypt++;
	}
	return (encrypt);
}

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
		dest[(*j)++] = src[(*i)++];
		while (src[*i] && src[*i] != '\"')
		{
			dest[(*j)++] = src[(*i)++];
		}
		dest[(*j)++] = src[(*i)++];
	}
	else if (src[*i] && src[*i] == '\'')
	{	
		dest[(*j)++] = src[(*i)++];
		while (src[*i] && src[*i] != '\'')
		{
			dest[(*j)++] = src[(*i)++];
		}
		dest[(*j)++] = src[(*i)++];
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
	count++;
	s++;
	args->quote_parse = 2;
	while (*s && *s != quote)
	{
		count++;
		s++;
	}
	count++;
	s++;
	return (count);
}
