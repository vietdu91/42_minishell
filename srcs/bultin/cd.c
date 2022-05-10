/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:08 by emtran            #+#    #+#             */
/*   Updated: 2022/05/09 11:27:40 by emtran           ###   ########.fr       */
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

int	check_nb_simple_args(t_pars_node *parser)
{
	t_pars_node	*node;
	int			i;

	i = 0;
	node = parser->next;
	while (node && node->type != PIPE)
	{
		if (node->type == SIMPLE_ARG)
			i++;
		node = node->next;
	}
	return (i);
}

void	cd_third_main(t_args *args, t_pars_node *node, char *oldpwd, \
bool *error)
{
	if (!node || !ft_strcmp(node->content_exp_sans_q, "~") || \
	!ft_strcmp(node->content_exp_sans_q, "") || \
	(node->type != OPTION && node->type != SIMPLE_ARG))
		cd_home(args, args->env, oldpwd, error);
	else if (!ft_strcmp(node->content_exp_sans_q, "-"))
		cd_moins(args, args->env, oldpwd, error);
	else if (!oldpwd && (!ft_strcmp(node->content_exp_sans_q, ".") \
	|| !ft_strcmp(node->content_exp_sans_q, "..")))
		error_because_lost_dir(oldpwd, node->content_exp_sans_q, \
		error);
	else
		find_cd(args, oldpwd, node->content_exp_sans_q, error);
}

int	cd_second_main(t_args *args, t_pars_node *node, char *oldpwd, \
int *nb_single_args)
{
	bool		error;

	error = FALSE;
	if (node->type == OPTION)
	{
		bad_cd(oldpwd, node, 1, &error);
		return (0);
	}
	else if (node->type == SIMPLE_ARG)
	{
		if (*nb_single_args > 1)
		{
			bad_cd(oldpwd, node, 2, &error);
			return (0);
		}
		else
			cd_third_main(args, node, oldpwd, &error);
		if (error == FALSE)
			g_exit_status = 0;
	}
	return (1);
}

void	cd_main(t_args *args, t_env_list *env, t_pars_node *parser)
{
	t_pars_node	*node;
	char		*oldpwd;
	bool		error;
	int			nb_simple_args;

	error = FALSE;
	nb_simple_args = 0;
	oldpwd = getcwd(NULL, 0);
	nb_simple_args = check_nb_simple_args(parser);
	node = parser->next;
	while (node && node->type != PIPE)
	{
		if (!cd_second_main(args, node, oldpwd, &nb_simple_args))
			return ;
		node = node->next;
	}
	if (!nb_simple_args)
		cd_home(args, env, oldpwd, &error);
	return ;
}
