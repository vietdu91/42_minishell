/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:08:22 by emtran            #+#    #+#             */
/*   Updated: 2022/05/17 21:02:30 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_error_and_exit(char *msg_error, t_args *args)
{
	ft_putstr(msg_error, 2);
	ft_putstr("\n", 2);
	free_all(args);
	exit(g_exit_status);
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
	int	i;

	i = 0;
	ft_putstr(msg_error, 2);
	while (sign[i] && i < 2)
	{
		ft_putchar(sign[i], 2);
		i++;
	}
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
