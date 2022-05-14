/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:41:31 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/14 20:18:12 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	close_loop_execution(t_pars_node *i, t_pars_list *l, int datas[5])
{
	if (i->fds[0] > 0)
		close(i->fds[0]);
	if (i->fds[1] > 0)
		close(i->fds[1]);
	if (datas[0] > 1)
		close(l->pipe[1]);
	if (i->previous && l->pipe[1] > 0 && i->previous->type == PIPE)
		close(l->pipe[1]);
	return (0);
}

int	close_loop_execution_parent(int j, t_pars_list *l, int datas[5])
{
	int			status;

	status = 0;
	while (j < l->length)
	{
		if ((0 < waitpid(0, &status, 0) && (WIFEXITED(status))))
			g_exit_status = WEXITSTATUS(status);
		j++;
	}	
	unlink("/tmp/.zuzu");
	close(datas[3]);
	close(datas[4]);
	if (l->pipe[0] > 0)
		close(l->pipe[0]);
	if (l->pipe[1] > 0)
		close(l->pipe[1]);
	ft_putstr("parent datas[2] == ", 2);
	ft_putnbr(datas[2], 2);
	ft_putstr("\n", 2);
	ft_putstr("parent datas[3] == ", 2);
	ft_putnbr(datas[3], 2);
	ft_putstr("\n", 2);
	ft_putstr("parent datas[4] == ", 2);
	ft_putnbr(datas[4], 2);
	ft_putstr("\n", 2);
	ft_putstr("parent pipe[0] == ", 2);
	ft_putnbr(l->pipe[0], 2);
	ft_putstr("\n", 2);
	ft_putstr("parent pipe[1] == ", 2);
	ft_putnbr(l->pipe[1], 2);
	ft_putstr("\n", 2);
	return (0);
}

int	return_datas_zero_fail(int datas[5], t_pars_list *l)
{
	close_maestro(datas, l);
	return (-1);
}
