/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_close_norm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 18:09:58 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/17 20:28:22 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	datas_middle_part_2(t_pars_node *cpy, int datas[5], t_pars_list *l)
{
	if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
	{
		if (dup2(cpy->fds[1], STDOUT_FILENO) < 0)
			return (-1);
		ft_close(l->pipe[0], "file here \n");
		ft_close(l->pipe[1], "file here \n");
		ft_close(datas[2], "file here \n");
	}
	else
	{
		if (dup2(l->pipe[1], STDOUT_FILENO) < 0)
			return (-1);
		ft_close(l->pipe[1], "file here \n");
		ft_close(datas[3], "file here \n");
		ft_close(datas[4], "file here \n");
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
			ft_close(l->pipe[0], "zero part 2\n");
			if (datas[2] > 0)
				ft_close(datas[2], "zero part 2\n");
			ft_close(l->pipe[1], "zero part 2\n");
		}
	}
	if (cpy->fds[0] > 1)
		close(cpy->fds[0]);
	if (cpy->fds[1] > 1)
		ft_close(cpy->fds[1], "zero part 2\n");
	ft_close(datas[3], "3 zero part 2\n");
	ft_close(datas[4], "4 zero part 2\n");
	return (0);
}
