/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:29:23 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/06 17:07:57 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	simple_exec(t_args *args, t_pars_list *l)
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	// gerer infile
	// gerer outfile
	// gerer heredoc 
	if (pid == 0)
	{
		execve(l->head->path, l->head->cmds, args->env_tab);
		// free
	}
	return (0);
}
