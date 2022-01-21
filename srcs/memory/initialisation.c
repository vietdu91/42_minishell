/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:26:48 by emtran            #+#    #+#             */
/*   Updated: 2022/01/21 14:35:20 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_all(t_args *args, char **envp)
{
	args->path = find_path(envp);
	args->pwd = find_pwd(envp);
	args->oldpwd = find_oldpwd(envp);
	args->home = find_home(envp);
	get_env(args, envp);
}

void	init_struct(t_args *args)
{
	args->builtin->tab_builtin = NULL;
	args->builtin->cd->cd_on = 0;
	args->builtin->echo->echo_on = 0;
	args->builtin->echo->option_n = 0;
	args->builtin->export->export_on = 0;
	args->builtin->history->history_on = 0;
	args->builtin->pwd->pwd_on = 0;
	args->builtin->unset->unset_on = 0;
}

void	init_and_set_all(t_args *args, char **envp)
{
	g_exit_status = 0;
	args->buffer = NULL;
//	args->env = NULL;
	args->path = NULL;
	args->pwd = NULL;
	args->oldpwd = NULL;
	args->nb_commands = 0;
//	init_struct(args);
	set_all(args, envp);
}