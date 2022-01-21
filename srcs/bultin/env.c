/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:59:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/21 17:43:29 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env_list	*init_env_list(void)
{
	t_env_list	*env_list;
	t_env		*env;

	env_list = NULL;
	env_list = (t_env_list *)malloc(sizeof(t_env_list));
	if (!env_list)
		return (NULL);
	env_list->head = NULL;
	env_list->length = 0;
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (NULL);
	env->next = NULL;
	env->line = NULL;
	env->variable = NULL;
	env->content = NULL;
	env->index = 0;
	env_list->head = env;
	return (env_list);
}

void	get_env(t_args *args, char **envp)
{
	t_env_list	*env_list;
	int			i;

	(void) args;
	env_list = init_env_list();
	i = 0;
	if (!envp)
		return ;
	free(env_list->head);
	free(env_list);
}
