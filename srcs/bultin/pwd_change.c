/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:26:54 by emtran            #+#    #+#             */
/*   Updated: 2022/02/17 15:04:21 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	change_pwd_env(char *newpwd, t_args *args)
{
	t_env	*node;
	char	*pwd_str;

	if (!args || !newpwd)
		return ;
	node = NULL;
	node = args->env->head;
	pwd_str = ft_strdup("PWD=");
	while (node)
	{
		if (node->var_id == 1)
		{
			free(node->content);
			node->content = ft_strdup(newpwd);
			free(node->line);
			node->line = ft_strjoin(pwd_str, newpwd);
			return ;
		}
		node = node->next;
	}
}

void	change_oldpwd_env(char *newpwd, t_args *args)
{
	t_env	*node;
	char	*oldpwd_str;

	if (!args || !newpwd)
		return ;
	if (!args->builtin->oldpwd_on)
	{
		args->builtin->oldpwd_on = 1;
		return ;
	}
	node = NULL;
	node = args->env->head;
	oldpwd_str = ft_strdup("OLDPWD=");
	while (node)
	{
		if (node->var_id == 2)
		{
			free(node->content);
			node->content = ft_strdup(newpwd);
			free(node->line);
			node->line = ft_strjoin(oldpwd_str, newpwd);
			return ;
		}
		node = node->next;
	}
}

void	change_pwd_export(char *newpwd, t_args *args)
{
	t_env	*node;
	char	*pwd_str;

	if (!args || !newpwd)
		return ;
	node = NULL;
	node = args->export->head;
	pwd_str = ft_strdup("PWD=");
	while (node)
	{
		if (node->var_id == 1)
		{
			free(node->content);
			node->content = ft_strdup(newpwd);
			free(node->line);
			node->line = ft_strjoin(pwd_str, newpwd);
			return ;
		}
		node = node->next;
	}
}

void	change_oldpwd_export(char *newpwd, t_args *args)
{
	t_env	*node;
	char	*oldpwd_str;

	if (!args || !newpwd)
		return ;
	if (!args->builtin->oldpwd_on)
	{
		args->builtin->oldpwd_on = 1;
		return ;
	}
	node = NULL;
	node = args->export->head;
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
