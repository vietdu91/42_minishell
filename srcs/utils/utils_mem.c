/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:50:51 by emtran            #+#    #+#             */
/*   Updated: 2022/01/13 17:37:24 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char			*chdest;
	char			*chsrc;
	unsigned int	i;

	chdest = (char *)dest;
	chsrc = (char *)src;
	if (dest == 0 && src == 0)
		return (0);
	i = 0;
	while (i < count)
	{
		chdest[i] = chsrc[i];
		i++;
	}
	return (dest);
}

char	*ft_strcalloc(size_t size)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < size + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
