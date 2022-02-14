/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:28:57 by emtran            #+#    #+#             */
/*   Updated: 2022/02/14 16:36:21 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*n_str;

	i = 0;
	while (str[i])
		i++;
	n_str = malloc(sizeof(char) * (i + 1));
	if (!n_str)
		return (NULL);
	i = -1;
	while (str[++i])
		n_str[i] = str[i];
	n_str[i] = 0;
	return (n_str);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}
/*
char	*join_char(char *str, char c)
{
	int		i;
	int		len;
	char	*joined;

	i = -1;
	if (str[0] != 0)
		len = ft_strlen(str) + 1;
	else
		len = 1 + 1;
	joined = malloc(sizeof(char) * (len + 1));
	if (!joined)
		return (NULL);
	while (++i < (int)ft_strlen(str))
	{
		joined[i] = str[i];
	}
	joined[i] = c;
	i++;
	joined[i] = 0;
	free(str);
	return (joined);
}*/

size_t	ft_strlcpy_w_quotes(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (src[i] && i < size - 1)
			cpy_with_double_quotes(&i, &j, dest, src);
		dest[j] = 0;
	}
	return (ft_strlen(src));
}

char	*ft_strjoin_one_c(char *s1, char s2)
{
	unsigned int	len_1;
	char			*str;

	if (s2 != 0)
	{
		len_1 = ft_strlen(s1);
		str = (char *)malloc(sizeof(char) * (len_1 + 1 + 1));
		if (!str)
			return (0);
		ft_memcpy(str, s1, len_1);
		ft_memcpy_with_one_char(str + len_1, s2, 1 + 1);
		free(s1);
		s1 = NULL;
		str[len_1 + 1] = '\0';
		return (str);
	}
	return (s1);
}
