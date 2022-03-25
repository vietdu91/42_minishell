/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:08:22 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 02:07:32 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_error_and_exit(unsigned char *msg_error, t_args *args)
{
	ft_putstr(msg_error, 2);
	ft_putstr("\n", 2);
	free_all(args);
	exit(EXIT_FAILURE);
}

void	intersection_of_errors(int a, t_args *args)
{
	if (a == 1)
		print_error_and_exit(ERR_NOENV, args);
	if (a == 2)
		print_error_and_exit(ERR_MALLOC, args);
}


void	print_syntax_error(unsigned char *msg_error, unsigned char *sign)
{
	ft_putstr(msg_error, 2);
	ft_putstr(sign, 2);
	ft_putstr("'\n", 2);
}

void	print_error(unsigned char *sys, unsigned char *cmd, unsigned char *arg, unsigned char *error)
{
	ft_putstr(sys, 2);
	ft_putstr(cmd, 2);
	if (arg)
	{
		ft_putstr(arg, 2);
		ft_putstr(": ", 2);
	}
	ft_putstr(error, 2);
}

void	print_error_w_quote(unsigned char *sys, unsigned char *cmd, unsigned char *arg, unsigned char *error)
{
	ft_putstr(sys, 2);
	ft_putstr(cmd, 2);
	if (arg)
	{
		ft_putchar('`', 2);
		ft_putstr(arg, 2);
		ft_putstr("': ", 2);
	}
	ft_putstr(error, 2);
}

