/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2021/12/30 18:47:37 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_putstr(char *str, int fd)
{
	int	a;

	a = ft_strlen(str);
	write(fd, str, a);
	a++;
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}

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
