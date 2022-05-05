/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:09:33 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/02 23:12:25 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	close_maestro(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	if (cpy->fds[0] > 0)
		close(cpy->fds[0]);
	if (cpy->fds[1] > 0)
		close(cpy->fds[1]);
	close(datas[2]);
	if (datas[0] < datas[1])
		close(l->pipe[1]);
	else
		close(l->pipe[0]);
	return (0);
}

int	datas_zero(int datas[5], t_pars_list *l)
{
	if (datas[1] > 1)
	{
		close(l->pipe[0]);
		if (dup2(l->pipe[1], STDOUT_FILENO) < 0)
			return (-1);
		close(datas[2]);
		close(l->pipe[1]);
	}
	return (0);
}

int	dup_maestro(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	if (cpy->fds[0] > 0)
	{
		if (datas[0] == 1)
		{
			close(l->pipe[0]);
			close(l->pipe[1]);
		}
		if (dup2(cpy->fds[0], STDIN_FILENO) < 0)
			return (-1);
	}
	if (cpy->fds[1] > 0)
	{
		close(l->pipe[1]);
		if (dup2(cpy->fds[1], STDOUT_FILENO) < 0)
			return (-1);
	}
	if (datas[0] == 1)
		return (datas_zero(datas, l));
	else if (datas[0] == datas[1])
	{
		// close(datas[2]);
		// close(datas[2]);
		if (dup2(datas[2], STDIN_FILENO) < 0)
			return (-1);
		if (cpy->fds[1] > 0)
			close(cpy->fds[1]);
		close(l->pipe[1]);
		close(l->pipe[0]);
	}
	else
	{
		if (cpy->fds[0] == 0)
		{
			if (dup2(datas[2], STDIN_FILENO) < 0)
				return (-1);
			close(datas[2]);
		}
		if (cpy->fds[1] == 0)
		{
			if (dup2(l->pipe[1], STDOUT_FILENO) < 0)
				return (-1);
			close(l->pipe[1]);
		}
		// if (datas[2] > 0)
		// {
		// 	ft_putstr("DATAS[2]\n", 2);
		// }
	}
	return (0);
}
