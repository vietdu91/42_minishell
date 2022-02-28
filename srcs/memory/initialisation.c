/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:26:48 by emtran            #+#    #+#             */
/*   Updated: 2022/02/28 17:16:59 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	set_all(t_args *args, char **envp)
{
	args->path = find_path(envp);
	args->pwd = find_pwd(envp);
	args->home = find_home(envp);
	if (!envp[0])
		get_env_if_no_env(args);
	else
		get_env(args, envp);
	get_export(args);
	args->parser = NULL;
//	init_parsing_list(&args->parser);
}

void	init_struct(t_args *args)
{
	args->builtin = (t_builtin *)malloc(sizeof(t_builtin));
	if (!args->builtin)
		intersection_of_errors(2, args);
	args->builtin->oldpwd_on = 0;
	args->builtin->oldpwd = NULL;
}

void	init_and_set_all(t_args *args, char **envp)
{
	g_exit_status = 0;
	args->buffer = NULL;
	args->path = NULL;
	args->path_to_try = NULL;
	args->final_path = NULL;
	args->pwd = NULL;
	args->quote_parse = 0;
	args->nb_commands = 0;
	init_struct(args);
	set_all(args, envp);
}
