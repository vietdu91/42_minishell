/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_no_env.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:44:40 by emtran            #+#    #+#             */
/*   Updated: 2022/03/07 17:13:52 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_env_if_no_env(t_args *args)
{
	char	*pwd_model;
	char	*pwd;
	char	*oldpwd;
	char	*shlvl;

	if (!args)
		return ;
	pwd_model = ft_strdup("PWD=");
	args->export = init_env_list(args->export, args);
	args->env = init_env_list(args->env, args);
	pwd = ft_strjoin(pwd_model, getcwd(NULL, 0));
	shlvl = ft_strdup("SHLVL=1");
	oldpwd = ft_strdup("OLDPWD=");
	add_var_to_env(args->env, pwd, args);
	add_var_to_env(args->env, shlvl, args);
	add_var_to_env(args->env, oldpwd, args);
	free(pwd_model);
}
