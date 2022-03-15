/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:22:49 by emtran            #+#    #+#             */
/*   Updated: 2022/03/15 15:12:48 by dyoula           ###   ########.fr       */
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
		invalid_option(node->next, CMD_PWD);
		return ;
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return ;
	ft_putstr(pwd, 1);
	ft_putchar('\n', 1);
	change_pwd_env(pwd, args->env);
	change_pwd_export(pwd, args->export);
	g_exit_status = 0;
	free(pwd);
}
