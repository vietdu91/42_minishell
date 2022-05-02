/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:39:17 by emtran            #+#    #+#             */
/*   Updated: 2022/01/23 10:52:46 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_ctlr_c(int signal)
{
	if (signal == SIGINT)
	{
		ft_putstr("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_exit_status = 130;
	}
}

void	ignore_signals(void)
{
	signal(SIGSEGV, SIG_IGN);
	signal(SIGABRT, SIG_IGN);
	signal(SIGTRAP, SIG_IGN);
	signal(SIGBUS, SIG_IGN);
}

void	recover_signals(void)
{
	signal(SIGSEGV, SIG_DFL);
	signal(SIGABRT, SIG_DFL);
	signal(SIGTRAP, SIG_DFL);
	signal(SIGBUS, SIG_DFL);
}

void	handle_status(int sig)
{
	const char	*signums[] = {
	[SIGINT] = "\n",
	[SIGSEGV] = "Segmentation fault\n",
	[SIGABRT] = "Abort\n",
	[SIGQUIT] = "Quit\n",
	[SIGTRAP] = "Trace/Breakpoint Trap\n",
	[SIGBUS] = "Bus Error\n",
	};

	if (signums[sig])
		ft_putstr((char *)signums[sig], STDERR_FILENO);
	g_exit_status = (sig + 128);
}