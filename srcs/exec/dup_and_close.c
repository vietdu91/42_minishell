/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:09:33 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/19 16:29:08 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	close_maestro(int datas[2], t_pars_list *l, t_pars_node *cpy)
{
	if (cpy->fds[0] > 0)
		close(cpy->fds[0]);
	if (cpy->fds[1] > 0)
		close(cpy->fds[1]);
	close(datas[2]);
	close(l->pipe[0]);
	close(l->pipe[1]);
	return (0);
}

int	dup_maestro(int datas[2], t_pars_list *l, t_pars_node *cpy)
{
	if (datas[0] == 0)
	{
		if (cpy->fds[0] > 0)
		{
			if (dup2(cpy->fds[0], 0) < 0)
				return (-1);
		}
		if (cpy->fds[1] > 0)
		{
			if (dup2(cpy->fds[1], 1) < 0)
				return (-1);
		}
		else if (datas[1] > 1)
		{
			if (dup2(l->pipe[1], 1) < 0)
				return (-1);
		}
	}
	else if (datas[0] == datas[1] - 1)
	{
		if (cpy->fds[0] > 0)
		{
			if (dup2(cpy->fds[0], 0) < 0)
				return (-1);
		}
		else
		{
			if (dup2(datas[2], 0) < 0)
				return (-1);
		}
	}
	else
	{
		if (cpy->fds[0] > 0)
		{
			if (dup2(cpy->fds[0], 0) < 0)
				return (-1);
		}
		else
		{
			if (dup2(datas[2], 0) < 0)
				return (-1);	
		}
		if (cpy->fds[1] > 0)
		{
			if (dup2(cpy->fds[1], 1) < 0)
				return (-1);
		}
		else
		{
			if (dup2(l->pipe[1], 1) < 0)
				return (-1);
		}	
	}
	return (0);
}
