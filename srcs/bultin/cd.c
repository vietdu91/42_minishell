/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:08 by emtran            #+#    #+#             */
/*   Updated: 2022/03/06 17:32:49 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_main(t_args *args, t_env_list *env, t_pars_node *parser)
{
	t_pars_node	*node;
//	char		*path;

	(void) env;
	(void) parser;
	(void) args;
	node = parser->next;
	if (!node)
	{
		// mettre CD pour HOME
	}
	while (node)
	{
		if (node->type == 20)
		{
			invalid_option(node, CMD_CD);
			return ;
		}
		else if (node->next)
		{
			print_error(BASH, CMD_CD, NULL, ERR_MANY_ARG);
			g_exit_status = 1;
			return ;
		}
	}
/*	path = NULL;
	path = getcwd(NULL, 0);
	if (!path)
	{
		printf("bash: cd: HOME not set\n");
		g_exit_status = 1;
		return ;
	}
	if (args->builtin->oldpwd)
		free(args->builtin->oldpwd);
	args->builtin->oldpwd = ft_strdup(path);
	if (chdir(path) == -1)
		perror("bash: cd");
	change_pwd_env(path, args);
	change_pwd_export(path, args);*/
	g_exit_status = 0;
}
