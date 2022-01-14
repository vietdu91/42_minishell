/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:39:17 by emtran            #+#    #+#             */
/*   Updated: 2022/01/13 15:29:17 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_ctlr_c(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		printf(PROMPT);
		g_exit_status = 130;
	}
}
