/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:47 by emtran            #+#    #+#             */
/*   Updated: 2022/04/21 18:46:55 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_putnbr(int nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar('-', fd);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10, fd);
	ft_putchar(nb % 10 + 48, fd);
}

void	ft_putstr(char *str, int fd)
{
	while (*str)
		ft_putchar(*(str++), fd);
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
