/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:08 by emtran            #+#    #+#             */
/*   Updated: 2022/04/28 12:36:15 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	find_cd(t_args *args, char *oldpwd, char *path, bool *error)
{
	int		ret;
	char	*pwd;

	ret = chdir(path);
	pwd = getcwd(NULL, 0);
	if (ret < 0)
	{
		print_error(BASH, CMD_CD, path, ERR_DIR);
		g_exit_status = 1;
		*error = TRUE;
	}
	else
	{
		update_env(pwd, oldpwd, args);
		g_exit_status = 0;
	}
	free(pwd);
	free(oldpwd);
	return ;
}

void	bad_cd(char *oldpwd, t_pars_node *node, int way, bool *error)
{
	free(oldpwd);
	if (way == 1)
		invalid_option(node, CMD_CD);
	else if (way == 2)
	{
		print_error(BASH, CMD_CD, NULL, ERR_MANY_ARG);
		g_exit_status = 1;
	}
	*error = TRUE;
	return ;
}

void	cd_main(t_args *args, t_env_list *env, t_pars_node *parser)
{
	t_pars_node	*node;
	char		*oldpwd;
	bool		error;

	node = parser->next;
	error = FALSE;
	oldpwd = getcwd(NULL, 0);
	if (!node || !ft_strcmp(node->content_exp_sans_q, "~") || \
	!ft_strcmp(node->content_exp_sans_q, "") || (node->type != OPTION && \
	node->type != SIMPLE_ARG))
		cd_home(args, env, oldpwd, &error);
	else if (node->type == OPTION)
		bad_cd(oldpwd, node, 1, &error);
	else if (node->next)
		bad_cd(oldpwd, node, 2, &error);
	else if (!ft_strcmp(node->content_exp_sans_q, "-"))
		cd_moins(args, env, oldpwd, &error);
	else if (!oldpwd && (!ft_strcmp(node->content_exp_sans_q, ".") \
	|| !ft_strcmp(node->content_exp_sans_q, "..")))
		error_because_lost_dir(oldpwd, node->content_exp_sans_q, &error);
	else
		find_cd(args, oldpwd, node->content_exp_sans_q, &error);
	if (error == FALSE)
		g_exit_status = 0;
	return ;
}
