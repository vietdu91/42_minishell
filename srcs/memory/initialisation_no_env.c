/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_no_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:44:40 by emtran            #+#    #+#             */
/*   Updated: 2022/01/27 12:23:30 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_env_if_no_env(t_args *args)
{
	t_env	*node;
	char	*pwd;
	char	*oldpwd;
	char	*shlvl;

	(void) node;
	if (!args)
		return ;
	args->export = init_env_list(args->export, args);
	args->env = init_env_list(args->env, args);
	pwd = ft_strjoin("PWD=", getcwd(NULL, 0));
	shlvl = ft_strdup("SHLVL=1");
	oldpwd = ft_strdup("OLDPWD=");
	add_var_to_env(args->env, pwd, args);
	add_var_to_env(args->env, shlvl, args);
	add_var_to_env(args->env, oldpwd, args);
}
