/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:23:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/27 14:33:56 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	cd_main(char *path, t_args *args)
{
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
	change_pwd_export(path, args);
	g_exit_status = 0;
}
