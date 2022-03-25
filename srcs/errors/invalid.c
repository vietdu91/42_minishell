/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:55:17 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 02:07:01 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	invalid_option(t_pars_node *node, unsigned char *cmd)
{
	unsigned char	*option;

	option = malloc(sizeof(unsigned char) * (2 + 1));
	ft_strlcpy(option, node->content_exp_sans_q, 3);
	print_error(BASH, cmd, option, ERR_OPTION);
	g_exit_status = 2;
	free(option);
}