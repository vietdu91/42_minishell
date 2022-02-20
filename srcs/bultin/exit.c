/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:10:01 by emtran            #+#    #+#             */
/*   Updated: 2022/02/20 19:10:35 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Gestion du LONG_LONG_MAX et LONG_LONG_MIN
*/

void	exit_main(t_args *args, t_pars_node *parser)
{
	int			exit_status;
	t_pars_node	*node;

	node = parser->next;
	ft_putstr("exit\n", 1);
	if (node)
	{
		if (check_only_digits(node->nw_content))
		{
			ft_putstr("bash: exit: ", 2);
			ft_putstr(node->nw_content, 2);
			ft_putstr(": numeric argument required\n", 2);
			free_all(args);
			exit(2);
		}
		else if (node->next)
		{
			ft_putstr(ERR_MANY_ARG, 2);
			g_exit_status = 1;
			return ;
		}
		else
		{
			exit_status = ft_atoi(node->nw_content);
			free_all(args);
			exit(exit_status % 256);
		}
	}
	free_all(args);
	exit(EXIT_SUCCESS);
}
