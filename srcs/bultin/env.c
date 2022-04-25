/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:59:08 by emtran            #+#    #+#             */
/*   Updated: 2022/04/25 10:52:39 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_env(t_env *current)
{
	if (ft_strcmp(current->content, "\0"))
	{
		ft_putstr(current->line, STDOUT_FILENO);
		ft_putstr("\n", STDOUT_FILENO);
	}
}

void	display_env(t_pars_node *pars, t_env_list *env)
{
	t_env		*current;
	t_pars_node	*node;

	node = pars;
	if (!env)
		return ;
	while (node)
	{
		if (node->type == OPTION)
		{
			invalid_option(node, CMD_ENV);
			return ;
		}
		node = node->next;
	}
	current = NULL;
	current = env->head;
	while (current)
	{
		print_env(current);
		current = current->next;
	}
	g_exit_status = 0;
}

void	get_env(t_args *args, char **envp)
{
	int	i;

	i = 0;
	args->export = init_env_list(args->export, args);
	args->env = init_env_list(args->env, args);
	while (envp[i])
	{
		add_var_to_env(args->env, envp[i], args);
		i++;
	}
	g_exit_status = 0;
}

char	*find_content_in_env(char *var, t_env_list *env)
{
	t_env	*node;

	node = NULL;
	node = env->head;
	while (node)
	{
		if (!ft_strcmp(node->variable, var))
			return (node->content);
		node = node->next;
	}
	return (NULL);
}
