/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:22:49 by emtran            #+#    #+#             */
/*   Updated: 2022/04/24 19:04:43 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	pwd_main(t_pars_node *parser, t_args *args)
{
	t_pars_node	*node;
	char		*pwd;

	node = parser;
	if (node->next && node->next->type == OPTION)
	{
		invalid_option(node->next, CMD_PWD);
		return ;
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return ;
	// printf("stdin  = %d\n", STDOUT_FILENO);
	ft_putstr(pwd, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);
	// printf("hola pwd \n");
	change_pwd_env(pwd, args->env);
	change_pwd_export(pwd, args->export);
	g_exit_status = 0;
	free(pwd);
}
