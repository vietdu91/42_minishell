/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:39:17 by emtran            #+#    #+#             */
/*   Updated: 2022/01/11 18:27:34 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern t_data	g_data;

void	signal_ctlr_c(int signal)
{
	if (signal == SIGINT)
	{
		printf("\n");
		printf(PROMPT);
		g_data.exit_status = 130;
	}
}
