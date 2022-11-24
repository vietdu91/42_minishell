/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:41:31 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/17 20:26:47 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stdio.h>

void	ft_close(int fd, char *str)
{
	(void)str;
	close(fd);
}

int	close_loop_execution(t_pars_node *i, t_pars_list *l, int datas[5])
{
	if (i->fds[0] > 0)
		ft_close(i->fds[0], "after else parent\n");
	if (i->fds[1] > 0)
		ft_close(i->fds[1], "after else parent\n");
	if (datas[0] > 1)
		ft_close(l->pipe[1], "after else parent\n");
	if (i->previous && l->pipe[1] > 0 && i->previous->type == PIPE)
		ft_close(l->pipe[1], "after else parent\n");
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
	ft_close(datas[3], "after unlink \n");
	ft_close(datas[4], "after unlink \n");
	if (l->pipe[0] > 0)
		ft_close(l->pipe[0], "after unlink \n");
	if (l->pipe[1] > 0)
		ft_close(l->pipe[1], "after unlink \n");
	return (0);
}

int	return_datas_zero_fail(int datas[5], t_pars_list *l)
{
	close_maestro(datas, l);
	return (-1);
}
