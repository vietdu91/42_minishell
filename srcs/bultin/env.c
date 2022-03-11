/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:59:08 by emtran            #+#    #+#             */
/*   Updated: 2022/03/11 01:30:30 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
		if (ft_strcmp(current->content, "\0"))
			ft_putstr(current->line, 1);
			// printf("%s\n", current->line);
		current = current->next;
	}
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
