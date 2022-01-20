/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:10:01 by emtran            #+#    #+#             */
/*   Updated: 2022/01/18 15:52:11 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_main(t_args *args)
{
	ft_putstr("exit\n", 1);
	free_all(args);
	exit(EXIT_SUCCESS);
}

/* Faire modulo %256 pour g_exit_status
Gestion du LONG_LONG_MAX et LONG_LONG_MIN
*/
