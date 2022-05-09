/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:14:59 by emtran            #+#    #+#             */
/*   Updated: 2022/05/09 10:15:54 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_ctlr_c(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_exit_status = 130;
	}
}

void	signal_exec(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr("\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		g_exit_status = 130;
	}
	else if (signal == SIGQUIT)
	{
		ft_putstr("Quit (core dumped)\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		g_exit_status = 131;
	}
}

void	signal_segfault(int signal)
{
	if (signal == SIGSEGV)
	{
		ft_putstr("Segmentation fault (core dumped)\n", 1);
		g_exit_status = 139;
	}
}

void	signal_ignore(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar('\n', 1);
		g_exit_status = 130;
	}
	if (signal == SIGQUIT)
	{
		ft_putstr("Quit (core dumped)\n", 1);
		g_exit_status = 131;
	}
}

void	signal_heredoc(int signal)
{
	if (signal == SIGINT)
	{
		g_exit_status = 130;
		write(1, "\n", 1);
		rl_replace_line("", 0);
	//	close(STDIN_FILENO);
	}
	if (signal == SIGQUIT)
	{
		ft_putstr("Quit (core dumped)\n", 1);
		g_exit_status = 131;
		close(STDIN_FILENO);
	}
}
