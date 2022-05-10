/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_change.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:26:54 by emtran            #+#    #+#             */
/*   Updated: 2022/05/06 17:16:59 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	update_env(char *pwd, char *oldpwd, t_args *args)
{
	char	*oldpwd_var;
	char	*new_oldpwd;

	if (!find_content_in_env("OLDPWD", args->env))
	{
		oldpwd_var = ft_strdup("OLDPWD=");
		new_oldpwd = ft_strjoin(oldpwd_var, oldpwd);
		add_var_to_env(args->env, new_oldpwd, args);
		add_var_to_env(args->export, new_oldpwd, args);
		free(new_oldpwd);
	}
	if (oldpwd)
	{
		change_oldpwd_env(oldpwd, args->env);
		change_oldpwd_export(oldpwd, args->export);
	}
	if (pwd && find_content_in_env("PWD", args->env))
	{
		change_pwd_env(pwd, args->env);
		change_pwd_export(pwd, args->export);
	}
	g_exit_status = 0;
}

void	change_pwd_env(char *newpwd, t_env_list *env)
{
	t_env	*node;
	char	*pwd;

	if (!env || !newpwd)
		return ;
	node = NULL;
	node = env->head;
	pwd = ft_strdup("PWD=");
	while (node)
	{
		if (node->var_id == 1)
		{
			free(node->content);
			node->content = ft_strdup(newpwd);
			free(node->content_trim);
			node->content_trim = set_content_trim_env(node->content, ' ');
			node->content_trim = remove_interior_spaces(node->content_trim);
			free(node->line);
			node->line = ft_strjoin(pwd, newpwd);
			return ;
		}
		node = node->next;
	}
	free(pwd);
}

void	change_oldpwd_env(char *newpwd, t_env_list *env)
{
	t_env	*node;
	char	*oldpwd;

	if (!env || !newpwd)
		return ;
	node = NULL;
	node = env->head;
	oldpwd = ft_strdup("OLDPWD=");
	while (node)
	{
		if (node->var_id == 2)
		{
			free(node->content);
			node->content = ft_strdup(newpwd);
			free(node->content_trim);
			node->content_trim = set_content_trim_env(node->content, ' ');
			node->content_trim = remove_interior_spaces(node->content_trim);
			free(node->line);
			node->line = ft_strjoin(oldpwd, newpwd);
			return ;
		}
		node = node->next;
	}
	free(oldpwd);
}

void	change_pwd_export(char *newpwd, t_env_list *export)
{
	t_env	*node;
	char	*pwd;

	if (!export || !newpwd)
		return ;
	node = NULL;
	node = export->head;
	pwd = ft_strdup("PWD=");
	while (node)
	{
		if (node->var_id == 1)
		{
			free(node->content);
			node->content = ft_strdup(newpwd);
			free(node->content_trim);
			node->content_trim = set_content_trim_env(node->content, ' ');
			node->content_trim = remove_interior_spaces(node->content_trim);
			free(node->line);
			node->line = ft_strjoin(pwd, newpwd);
			return ;
		}
		node = node->next;
	}
	free(pwd);
}

void	change_oldpwd_export(char *newpwd, t_env_list *export)
{
	t_env	*node;
	char	*oldpwd;

	if (!export || !newpwd)
		return ;
	node = NULL;
	node = export->head;
	oldpwd = ft_strdup("OLDPWD=");
	while (node)
	{
		if (node->var_id == 2)
		{
			free(node->content);
			node->content = ft_strdup(newpwd);
			free(node->content_trim);
			node->content_trim = set_content_trim_env(node->content, ' ');
			node->content_trim = remove_interior_spaces(node->content_trim);
			free(node->line);
			node->line = ft_strjoin(oldpwd, newpwd);
			return ;
		}
		node = node->next;
	}
	free(oldpwd);
}
