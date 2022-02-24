/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:24:01 by emtran            #+#    #+#             */
/*   Updated: 2022/02/24 11:04:22 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_option(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != '-')
			break ;
		i++;
		while (str[i] == 'n')
		{
			i++;
		}
		break ;
	}
	if (str[i] != '\0')
		return (1);
	return (0);
}

void	echo_main(t_args *args, t_pars_node *parser)
{
	t_pars_node	*node;
	int			ding_dong;
	int			option;

	(void) args;
	ding_dong = 0;
	option = 0;
	node = parser->next;
	while (node)
	{
		if (!check_option(node->content_exp_sans_q))
			option = 1;
		else
			break ;
		node = node->next;
	}
	while (node && !type_meta(node->type))
	{
		if (ding_dong == 1)
			ft_putchar(' ', 1);
//		printf("CONTENT 0 : %c === CONTENT 1 : %c\n", node->content_exp[0], node->content_exp[1]);
		if (node->content_exp_sans_q[0] == '\0' && \
		(!is_quote(node->content_exp[0] && !is_quote(node->content_exp[1]))))
			ding_dong = 0;
		else
			ding_dong = 1;
		ft_putstr(node->content_exp_sans_q, 1);
		node = node->next;
	}
	if (!option)
		ft_putchar('\n', 1);
}
