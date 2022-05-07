/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:22:49 by emtran            #+#    #+#             */
/*   Updated: 2022/05/06 16:47:20 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_because_lost_dir_pwd(char *pwd)
{
	ft_putstr("pwd: error retrieving current directory: ", 2);
	ft_putstr("getcwd: cannot access parent directories: ", 2);
	perror(pwd);
	g_exit_status = 1;
}

void	pwd_main(t_pars_node *parser, t_args *args)
{
	t_pars_node	*node;
	char		*pwd;

	node = parser;
	while (node)
	{
		if (node && node->type == OPTION)
		{
			invalid_option(node, CMD_PWD);
			return ;
		}
		node = node->next;
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		error_because_lost_dir_pwd(pwd);
		return ;
	}
	ft_putstr(pwd, STDOUT_FILENO);
	ft_putchar('\n', STDOUT_FILENO);
	change_pwd_env(pwd, args->env);
	change_pwd_export(pwd, args->export);
	g_exit_status = 0;
	free(pwd);
}
