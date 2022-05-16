/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:09:33 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/16 21:37:33 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	close_maestro(int datas[5], t_pars_list *l)
{
	t_pars_node	*node;

	if (datas[2] > 0)
		ft_close(datas[2], l->pid);
	if (datas[0] < datas[1])
		ft_close(l->pipe[1], l->pid);
	else
		ft_close(l->pipe[0], l->pid);
	node = l->head;
	while (node)
	{		
		if (node->fds[0] > 0)
			ft_close(node->fds[0], l->pid);
		if (node->fds[1] > 0)
			ft_close(node->fds[1], l->pid);
	}
	return (0);
}

	void	print_fd(int datas[5], t_pars_list *l)
{
	ft_putstr("datas[2] == ", 2);
	ft_putnbr(datas[2], 2);
	ft_putstr("\n", 2);
	ft_putstr("datas[3] == ", 2);
	ft_putnbr(datas[3], 2);
	ft_putstr("\n", 2);
	ft_putstr("datas[4] == ", 2);
	ft_putnbr(datas[4], 2);
	ft_putstr("\n", 2);
	ft_putstr("pipe[0] == ", 2);
	ft_putnbr(l->pipe[0], 2);
	ft_putstr("\n", 2);
	ft_putstr("pipe[1] == ", 2);
	ft_putnbr(l->pipe[1], 2);
	ft_putstr("\n", 2);
	// ft_putnbr(datas[2], 2);
	// ft_putnbr(datas[2], 2);
}

int	datas_zero(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	ft_putstr("zero\n", 2);
	print_fd(datas, l);
	if (datas[1] > 1)
	{
		dprintf(2, "dup2 cpy->fds: %d, %d, l->pipe: %d, %d, datas[2,3, 4]: %d, %d, %d\n", cpy->fds[0], cpy->fds[1], l->pipe[0], l->pipe[1], datas[2],datas[3], datas[4]);
		if (cpy->fds[0] > 0 && dup2(cpy->fds[0], STDIN_FILENO) < 0)
		{
			return (return_datas_zero_fail(datas, l));
		}
		dprintf(2, "OUTTTT = %d\n", cpy->fds[1]);
		if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
		{
			return (return_datas_zero_fail(datas, l));
		}
		else if (cpy->fds[1] == 0 && dup2(l->pipe[1], STDOUT_FILENO) < 0)
			return (return_datas_zero_fail(datas, l));
		ft_close(l->pipe[0], l->pid + 1);
		// ft_close(l->pipe[1], l->pid - 1);
		if (datas[2] > 0)
			ft_close(datas[2], l->pid + 2);
		ft_close(datas[3], l->pid + 3);
		ft_close(datas[4], l->pid + 4);
	}
	else
		if (datas_zero_part2(cpy, datas, l) == -1)
			return (return_datas_zero_fail(datas, l));
	return (0);
}

int	datas_end(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	ft_putstr("end\n", 2);
	print_fd(datas, l);
	dprintf(2, "dup2 cpy->fds: %d, %d, l->pipe: %d, %d, datas[2, 3, 4]: %d, %d, %d\n", cpy->fds[0], cpy->fds[1], l->pipe[0], l->pipe[1], datas[2], datas[3], datas[4]);
	if (cpy->fds[0] > 0 && dup2(cpy->fds[0], STDIN_FILENO) < 0)
	{
		close_maestro(datas, l);
		return (-1);
	}
	else if (cpy->fds[0] < 1 && dup2(datas[2], STDIN_FILENO) < 0)
	{
		close_maestro(datas, l);
		return (-1);
	}
	if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
	{
		close_maestro(datas, l);
		return (-1);
	}
	if (datas[2] > 0)
		ft_close(datas[2], l->pid + 5);
	if (cpy->fds[1] > 0)
		ft_close(cpy->fds[1], l->pid + 6);
	ft_close(l->pipe[1], l->pid + 7);
	ft_close(l->pipe[0], l->pid + 8);
	ft_close(datas[3], l->pid + 9);
	ft_close(datas[4], l->pid + 10);
	return (0);
}

int	datas_middle(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	ft_putstr("middle\n", 2);
	print_fd(datas, l);
	if (cpy->fds[0] > 0 && dup2(cpy->fds[0], STDIN_FILENO) < 0)
		return_datas_zero_fail(datas, l);
	else
	{
		if (dup2(datas[2], STDIN_FILENO) < 0)
			return (return_datas_zero_fail(datas, l));
		ft_close(datas[2], l->pid);
		ft_close(l->pipe[0], l->pid);
	}
	if (datas_middle_part_2(cpy, datas, l) < 0)
		return_datas_zero_fail(datas, l);
	return (0);
}

int	dup_maestro(int datas[5], t_pars_list *l, t_pars_node *cpy)
{
	if (datas[0] == 1)
		return (datas_zero(datas, l, cpy));
	else if (datas[0] == datas[1] && datas[1] > 1)
		datas_end(datas, l, cpy);
	else
		datas_middle(datas, l, cpy);
	return (0);
}
