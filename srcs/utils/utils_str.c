/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2022/03/22 01:45:59 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	if (str == 0)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (str1[i] == 0 && str2[i] == 0)
		return (0);
	else
	{
		if (str1[i] < str2[i])
			return (-1);
		else if (str1[i] > str2[i])
			return (1);
	}
	return (0);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len_1;
	unsigned int	len_2;
	char			*str;

	if (s2 != 0)
	{
		len_1 = ft_strlen(s1);
		len_2 = ft_strlen(s2);
		// printf("s1 = %s len 1 = %d\n", s1, len_1);
		// printf("s2 = %s, len 2 = %d\n", s2, len_2);
		str = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
		if (!str)
			return (0);
		ft_memcpy(str, s1, len_1);
		ft_memcpy(str + len_1, s2, len_2 + 1);
		free(s1);
		s1 = NULL;
		str[len_1 + len_2] = '\0';
		return (str);
	}
	return (s1);
}

char	*ft_strnstr(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return (s1);
	if (n == 0)
		return (NULL);
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i < n && s1[i + j])
		{
			if (s1[i + j] && s2[j + 1] == 0 && i + j < n)
				return (&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
