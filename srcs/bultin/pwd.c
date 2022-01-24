/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:22:49 by emtran            #+#    #+#             */
/*   Updated: 2022/01/24 15:43:48 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	change_pwd(char *newpwd, t_args *args)
{
	t_env	*node;

	if (!args || !newpwd)
		return ;
	node = NULL;
	node = args->env->head;
	while (node)
	{
		if (node->var_id == 1)
		{
			free(node->content);
			node->content = ft_strdup(newpwd);
			free(node->line);
			node->line = ft_strjoin("PWD=", newpwd);
			return ;
		}
		node = node->next;
	}
}

void	change_oldpwd(char *newpwd, t_args *args)
{
	t_env	*node;

	if (!args || !newpwd)
		return ;
	if (!args->builtin->oldpwd_on)
	{
		args->builtin->oldpwd_on = 1;
		return ;
	}
	node = NULL;
	node = args->env->head;
	while (node)
	{
		if (node->var_id == 2)
		{
			free(node->content);
			node->content = ft_strdup(newpwd);
			free(node->line);
			node->line = ft_strjoin("OLDPWD=", newpwd);
			return ;
		}
		node = node->next;
	}
}

int	pwd_main(t_args *args)
{
	char	*pwd;

	(void) args;
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		return (1);
	ft_putstr(pwd, 1);
	ft_putchar('\n', 1);
	change_pwd(pwd, args);
	g_exit_status = 0;
	free(pwd);
	return (0);
}