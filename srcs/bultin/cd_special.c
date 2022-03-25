/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:46:57 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 01:54:43 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	error_because_lost_dir(unsigned char *oldpwd, unsigned char *command)
{
	ft_putstr("chdir: error retrieving current directory: ", 2);
	ft_putstr("getcwd: cannot access parent directories: ", 2);
	perror(oldpwd);
	print_error(BASH, CMD_CD, command, ERR_STALE);
	g_exit_status = 1;
}

void	cd_moins(t_args *args, t_env_list *env, unsigned char *oldpwd)
{
	unsigned char	*new_oldpwd;

	if (!find_content_in_env("OLDPWD", env) && \
	!ft_strcmp(find_content_in_env("OLDPWD", env), ""))
	{
		print_error(BASH, CMD_CD, NULL, ERR_OLDPWD_NOTSET);
		g_exit_status = 1;
		return ;
	}
	new_oldpwd = find_content_in_env("OLDPWD", env);
	ft_putstr(new_oldpwd, 1);
	ft_putstr("\n", 1);
	find_cd(args, env, oldpwd, new_oldpwd);
	return ;
}

void	cd_home(t_args *args, t_env_list *env, unsigned char *oldpwd)
{
	unsigned char	*home;

	if (!find_content_in_env("HOME", env))
	{
		free(oldpwd);
		print_error(BASH, CMD_CD, NULL, ERR_HOME);
		g_exit_status = 1;
		return ;
	}
	home = find_content_in_env("HOME", env);
	find_cd(args, env, oldpwd, home);
	return ;
}
