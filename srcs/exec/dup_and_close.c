/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_and_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 01:09:33 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/14 19:28:43 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	close_maestro(int datas[5], t_pars_list *l)
{
	t_pars_node	*node;

	if (datas[2] > 0)
		close(datas[2]);
	if (datas[0] < datas[1])
		close(l->pipe[1]);
	else
		close(l->pipe[0]);
	node = l->head;
	while (node)
	{		
		if (node->fds[0] > 0)
			close(node->fds[0]);
		if (node->fds[1] > 0)
			close(node->fds[1]);
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
		if (cpy->fds[0] > 0 && dup2(cpy->fds[0], STDIN_FILENO) < 0)
			return (return_datas_zero_fail(datas, l));
		if (cpy->fds[1] > 0 && dup2(cpy->fds[1], STDOUT_FILENO) < 0)
			return (return_datas_zero_fail(datas, l));
		else if (cpy->fds[1] < 1 && dup2(l->pipe[1], STDOUT_FILENO) < 0)
			return (return_datas_zero_fail(datas, l));
		close(l->pipe[0]);
		if (datas[2] > 0)
			close(datas[2]);
		close(datas[3]);
		close(datas[4]);
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
		close(datas[2]);
	if (cpy->fds[1] > 0)
		close(cpy->fds[1]);
	close(l->pipe[1]);
	close(l->pipe[0]);
	close(datas[3]);
	close(datas[4]);
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
		close(datas[2]);
		close(l->pipe[0]);
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
