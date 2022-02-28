/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:22:49 by emtran            #+#    #+#             */
/*   Updated: 2022/02/28 17:03:40 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_main(t_pars_node *parser, t_args *args)
{
	t_pars_node	*node;
	char		*pwd;

	node = parser;
	if (node->next && node->next->type == 20)
	{
		pwd = malloc(sizeof(char) * (2 + 1));
		ft_strlcpy(pwd, node->next->content_exp_sans_q, 3);
		print_error(BASH, CMD_PWD, pwd, ERR_OPTION);
		g_exit_status = 2;
		free(pwd);
		return ;
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return ;
	ft_putstr(pwd, 1);
	ft_putchar('\n', 1);
	change_pwd_env(pwd, args);
	g_exit_status = 0;
	free(pwd);
}
