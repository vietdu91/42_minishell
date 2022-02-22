/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:24:01 by emtran            #+#    #+#             */
/*   Updated: 2022/02/22 19:09:07 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
int		check_option(char *str)
{
	int	i;

	i = 0;
		while (node->content_exp_sans_q[i])
		{
			if (node->content_exp_sans_q[i] != '-')
				break;
			i++;
			while (node->content_exp_sans_q[1] == 'n')
			{
				
				i++;
			}
		}
}*/

void	echo_main(t_args *args, t_pars_node *parser)
{
	t_pars_node	*node;
	int			ding_dong;
	int			option;

	(void) args;
	ding_dong = 0;
	option = 0;
	node = parser->next;
/*	while (node && note->type == 4)
	{

	}*/
	while (node && node->type == 5)
	{
		if (ding_dong == 1)
			ft_putchar(' ', 1);
		ding_dong = 1;
		ft_putstr(node->content_exp_sans_q, 1);
		node = node->next;
	}
	ft_putchar('\n', 1);
}
