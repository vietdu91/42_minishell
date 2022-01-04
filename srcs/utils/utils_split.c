/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:38:10 by emtran            #+#    #+#             */
/*   Updated: 2022/01/04 11:40:23 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	ft_wordcount(char const *s, char c)
{
	size_t	w;
	size_t	i;

	i = 1;
	w = 0;
	while (*s)
	{
		if (*s == c)
			i = 1;
		else
		{
			if (i == 1)
				w++;
			i = 0;
		}
		s++;
	}
	return (w);
}

size_t	ft_wordlen(char const *s, char c)
{
	size_t	a;

	a = 0;
	while (*s && *s != c)
	{
		s++;
		a++;
	}
	return (a);
}

char	**ft_freetamere(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	w;
	size_t	j;

	j = 0;
	if (!s)
		return (0);
	array = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!array)
		return (0);
	while (ft_wordcount(s, c))
	{
		while (*s == c && *s)
			s++;
		w = 0;
		array[j] = (char *)malloc(sizeof(char) * ft_wordlen(s, c) + 1);
		if (!array[j])
			return (ft_freetamere(array));
		while (*s && *s != c)
			array[j][w++] = *s++;
		array[j++][w] = '\0';
	}
	array[j] = 0;
	return (array);
}