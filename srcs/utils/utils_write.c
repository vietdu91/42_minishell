/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:15:47 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 01:50:32 by dyoula           ###   ########.fr       */
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
	int	a;

	// a = ft_strlen(str);
	// write(fd, str, a);
	while (*str)
	{
		ft_putchar(*(str++), fd);
		// a = *(str++);
		// (void)fd;
		// printf("a = %d\n", a);
	}
	// a++;
}

void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
