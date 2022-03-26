/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:40:14 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/26 17:38:10 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	size_word(char *s, char *c, t_args *args)
{
	int		count;

	count = 0;
	if (*s == '\"')
		count = size_word_with_quotes(s, args, '\"');
	else if (*s == '\'')
		count = size_word_with_quotes(s, args, '\'');
	else if (*s && is_charset(*s, c))
	{
		while (*s && is_charset(*s, c))
		{
			count++;
			s++;
		}
	}
	else if (*s && !is_charset(*s, c))
	{
		while (*s && !is_charset(*s, c))
		{
			count++;
			s++;
		}
	}
//	printf("	in size_word count = %d\n", count);
	return (count);
}

int	count_words(char *s, char *c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\"' && s[i])
			i = count_words_with_quotes(s, &count, i, '\"');
		else if (s[i] == '\'' && s[i])
			i = count_words_with_quotes(s, &count, i, '\'');
		else if (is_charset(s[i], c) && s[i])
		{
			count++;
			while (is_charset(s[i], c) && s[i])
				i++;
		}
		else if (!is_charset(s[i], c) && s[i])
		{
			count++;
			while (!is_charset(s[i], c) && s[i])
				i++;
		}
	}
	return (count);
}

int	ready_for_split(int nb_words, char *c, char *s, char **flag)
{
	if (!s)
		return (-10);
	*flag = s;
	nb_words = count_words(s, c);
	return (nb_words);
}

char	**create_split(char **split, int nb_words)
{
	split = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!split)
		return (NULL);
	split[nb_words] = NULL;
	return (split);
}

char	**ft_split_charset(char **split, char *s, char *c, t_args *args)
{
	char	*flag;
	int		nb_words;
	int		index;

	nb_words = 0;
	flag = NULL;
	// printf("string = %s\n", s);
	nb_words = ready_for_split(nb_words, c, s, &flag);
	split = create_split(split, nb_words);
	index = -1;
//	printf("in split_charset s = %s nb_words = %d\n", s, nb_words);
	while (++index < nb_words)
	{
		split[index] = malloc(sizeof(char) * (size_word(flag, c, args) + 1));
		if (!split[index])
			return (free_split(split, index));
		ft_strlcpy_w_quotes(split[index], flag, (size_word(flag, c, args) + 1));
		flag += (size_word(flag, c, args));
		if (args->quote_parse)
			args->quote_parse = 0;
	}
	return (split);
}
