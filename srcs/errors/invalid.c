/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:55:17 by emtran            #+#    #+#             */
/*   Updated: 2022/05/03 17:36:56 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	invalid_option(t_pars_node *node, char *cmd)
{
	char	*option;

	option = malloc(sizeof(char) * (2 + 1));
	ft_strlcpy(option, node->content_exp_sans_q, 3);
	print_error(BASH, cmd, option, ERR_OPTION);
	g_exit_status = 2;
	free(option);
}

int	print_syntax_error_meta(char *sign)
{
	print_syntax_error(ERR_TOKEN, sign);
	g_exit_status = 2;
	return (-1);
}
