/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:58:09 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/17 19:58:39 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	dup_pid(t_pars_node *i, t_args *args, int datas[5], int n)
{
	dup_maestro(datas, args->parser, i);
	pid_zero_execution(i, args, datas[1], datas);
	if (n == 1)
	{
		free_all(args);
		exit (g_exit_status);
	}
}
