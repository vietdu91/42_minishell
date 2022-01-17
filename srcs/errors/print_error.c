/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:08:22 by emtran            #+#    #+#             */
/*   Updated: 2022/01/17 15:37:11 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fork_of_errors(int a, t_args *args)
{
	if (a == 1)
		print_error(ERR_NOENV, args);
	if (a == 2)
		print_error(ERR_MALLOC, args);
}

void	print_error(char *msg_error, t_args *args)
{
	ft_putstr(msg_error, 2);
	ft_putstr("\n", 2);
	free_all(args);
	exit(EXIT_FAILURE);
}

void	print_syntax_error(char *msg_error, char sign, int a)
{
	if (a == 1)
		ft_putstr(msg_error, 2);
	else
		ft_putstr(msg_error, 2);
	ft_putchar(sign, 2);
	ft_putstr("'\n", 2);
}
