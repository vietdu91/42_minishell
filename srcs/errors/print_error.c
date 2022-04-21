/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:08:22 by emtran            #+#    #+#             */
/*   Updated: 2022/04/21 11:12:23 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_error_and_exit(char *msg_error, t_args *args)
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

void	print_syntax_error(char *msg_error, char *sign)
{
	ft_putstr(msg_error, 2);
	ft_putstr(sign, 2);
	ft_putstr("'\n", 2);
}

void	print_error(char *sys, char *cmd, char *arg, char *error)
{
	ft_putstr(sys, STDERR_FILENO);
	if (cmd)
		ft_putstr(cmd, STDERR_FILENO);
	if (arg)
	{
		ft_putstr(arg, STDERR_FILENO);
		ft_putstr(": ", STDERR_FILENO);
	}
	ft_putstr(error, STDERR_FILENO);
}

void	print_error_w_quote(char *sys, char *cmd, char *arg, char *error)
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
