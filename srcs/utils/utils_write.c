/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:47 by emtran            #+#    #+#             */
/*   Updated: 2022/05/06 17:08:42 by dyoula           ###   ########.fr       */
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
	// ft_putnbr(fd, 2);
	// ft_putstr("\n", 2);
	write(fd, &c, 1);
}
