/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_charset.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 19:40:14 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/02 21:32:46 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**free_split(char **split, int index)
{
	while (index >= 0)
		free(split[index--]);
	free(split);
	return (NULL);
}

int	is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (c == charset[i])
			return (1);
	}
	return (0);
}

int	size_meta(char *s, char *c)
{
	int		count;

	count = 0;
	while (is_charset(*s, c) && *s)
	{
		count++;
		s++;
	}
	return (count);
}

int	size_word(char *s, char *c)
{
	int		count;

	count = 0;
	while (!is_charset(*s, c) && *s)
	{
		count++;
		s++;
	}
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
		while (is_charset(s[i], c) && s[i])
		{
			count++;
			while (is_charset(s[i], c) && s[i])
			{
				i++;
			}
		}
		if (!is_charset(s[i], c) && s[i])
		{
			count++;
			while (!is_charset(s[i], c) && s[i])
			{
				i++;
			}
		}
	}
	return (count);
}

char	**ft_split_charset(char *s, char *c)
{
	char	**split;
	char	*flag;
	int		nb_words;
	int		index;

	if (!s)
		return (NULL);
	flag = (char *)s;
	nb_words = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!split)
		return (NULL);
	split[nb_words] = NULL;
	index = -1;
	while (++index < nb_words)
	{
		printf("FLAG : %c\n", *flag);
		split[index] = (char *)malloc(sizeof(char) * (size_word(flag, c) + 1));
		if (!split[index])
			return (free_split(split, index));
		while (is_charset(*flag, c))
			flag++;
		ft_strlcpy(split[index], flag, size_word(flag, c) + 1);
		flag += (size_word(flag, c) + 1);
	}
	return (split);
}
