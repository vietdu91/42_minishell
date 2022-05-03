/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:08 by emtran            #+#    #+#             */
/*   Updated: 2022/05/03 17:36:51 by emtran           ###   ########.fr       */
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
	int			nb_simple_args;

	node = parser->next;
	error = FALSE;
	nb_simple_args = 0;
	oldpwd = getcwd(NULL, 0);
	while (node && node->type != PIPE)
	{
		if (node->type == SIMPLE_ARG)
			nb_simple_args++;
		node = node->next;
	}
	node = parser->next;
	while (node && node->type != PIPE)
	{
		if (node->type == OPTION)
		{
			bad_cd(oldpwd, node, 1, &error);
			return ;
		}
		else if (node->type == SIMPLE_ARG)
		{
			if (nb_simple_args > 1)
			{
				bad_cd(oldpwd, node, 2, &error);
				return ;
			}
			else
			{
				if (!node || !ft_strcmp(node->content_exp_sans_q, "~") || \
				!ft_strcmp(node->content_exp_sans_q, "") || \
				(node->type != OPTION && node->type != SIMPLE_ARG))
					cd_home(args, env, oldpwd, &error);
				else if (!ft_strcmp(node->content_exp_sans_q, "-"))
					cd_moins(args, env, oldpwd, &error);
				else if (!oldpwd && (!ft_strcmp(node->content_exp_sans_q, ".") \
				|| !ft_strcmp(node->content_exp_sans_q, "..")))
					error_because_lost_dir(oldpwd, node->content_exp_sans_q, \
					&error);
				else
					find_cd(args, oldpwd, node->content_exp_sans_q, &error);
			}
			if (error == FALSE)
				g_exit_status = 0;
		}
		node = node->next;
	}
	if (!nb_simple_args)
		cd_home(args, env, oldpwd, &error);
	return ;
}
