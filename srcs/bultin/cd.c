/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:50:34 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/25 14:52:00 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	find_cd(t_args *args, t_env_list *env, char *oldpwd, char *path)
{
	int		ret;
	char	*pwd;

	(void) env;
	ret = chdir(path);
	pwd = getcwd(NULL, 0);
	if (ret < 0)
	{
		print_error(BASH, CMD_CD, path, ERR_DIR);
		g_exit_status = 1;
	}
	else
		update_env(pwd, oldpwd, args);
	free(pwd);
	free(oldpwd);
	return ;
}

void	cd_main(t_args *args, t_env_list *env, t_pars_node *parser)
{
	t_pars_node	*node;
	char		*cdpath;
	char		*oldpwd;

	node = parser->next;
	oldpwd = getcwd(NULL, 0);
	cdpath = find_content_in_env("CDPATH", env);
	(void)cdpath;
	if (!node || !ft_strcmp(node->content_exp_sans_q, "~"))
		cd_home(args, env, oldpwd);
	if (node->type == 20)
	{
		free(oldpwd);
		invalid_option(node, CMD_CD);
	}
	else if (node->next)
	{
		free(oldpwd);
		print_error(BASH, CMD_CD, NULL, ERR_MANY_ARG);
		g_exit_status = 1;
	}
	else if (!ft_strcmp(node->content_exp_sans_q, "-"))
		cd_moins(args, env, oldpwd);
	else if (!oldpwd && (!ft_strcmp(node->content_exp_sans_q, ".") \
	|| !ft_strcmp(node->content_exp_sans_q, "..")))
		error_because_lost_dir(oldpwd, node->content_exp_sans_q);
/*	else if (ft_strlen(cdpath) > 0 && !ft_strcmp(node->content_exp_sans_q, ".") \
	&& !ft_strcmp(node->content_exp_sans_q, ".."))
	{
		
	}*/
	else
		find_cd(args, env, oldpwd, node->content_exp_sans_q);
	return ;
}
