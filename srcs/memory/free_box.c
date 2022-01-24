/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:57:13 by emtran            #+#    #+#             */
/*   Updated: 2022/01/24 15:43:36 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_d_tab(char **tb)
{
	int	i;

	i = -1;
	if (!tb)
		return ;
	while (tb[++i])
	{
		if (tb[i])
			free(tb[i]);
	}
	free(tb);
	tb = NULL;
}

void	free_t_lists(t_list *c)
{
	t_node 	*del;
	t_node	*i;

	if (!c)
		return ;
	i = c->head;
	while (i)
	{
		del = i;
		free(del->content);
		i = i->next;
		free(del);
	}
	free(c);
}

void	free_env_list(t_env_list *env)
{
	t_env	*del;
	t_env	*i;
	int		a;

	a = 0;
	if (!env)
		return ;
	i = env->head;
	while (i)
	{
		a++;
		del = i;
		free(del->line);
		free(del->variable);
		free(del->content);
		free(del);
		i = i->next;
	}
	free(env);
	env = NULL;
}

void	free_builtins(t_builtin *builtin)
{
	if (builtin->oldpwd)
		free(builtin->oldpwd);
	if (builtin)
		free(builtin);
}

void	free_all(t_args *args)
{
	if (!args)
		return ;
	if (args->buffer)
		free(args->buffer);
	free_builtins(args->builtin);
	free_env_list(args->env);
	free(args);
	rl_clear_history();
	args = NULL;
}
