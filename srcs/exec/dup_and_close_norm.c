/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_close_norm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:09:58 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 22:58:13 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	datas_middle_part_2(t_pars_node *cpy, int datas[5], t_pars_list *l)
{
	if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
	{
		if (dup2(cpy->fds[1], STDOUT_FILENO) < 0)
			return (-1);
		close(l->pipe[0]);
		close(l->pipe[1]);
		close(datas[2]);
	}
	else
	{
		if (dup2(l->pipe[1], STDOUT_FILENO) < 0)
			return (-1);
		close(l->pipe[1]);
		close(datas[3]);
		close(datas[4]);
	}
	return (0);
}

int	datas_zero_part2(t_pars_node *cpy, int datas[5], t_pars_list *l)
{
	if (cpy->fds[0] > 0 && dup2(cpy->fds[0], STDIN_FILENO) < 0)
		return (-1);
	if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
		return (-1);
	else if (l->pipe[1] > 0 && dup2(l->pipe[1], STDOUT_FILENO) < 0)
		return (-1);
	if (datas[1] > 1)
	{
		if (datas[1])
		{
			close(l->pipe[0]);
			if (datas[2] > 0)
				close(datas[2]);
			close(l->pipe[1]);
		}
	}
	close(datas[3]);
	close(datas[4]);
	return (0);
}
