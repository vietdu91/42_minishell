/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:06:17 by emtran            #+#    #+#             */
/*   Updated: 2022/02/02 17:42:40 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_env_list(t_env_list *env)
{
	t_env	*del;
	t_env	*i;

	if (!env)
		return ;
	i = env->head;
	while (i)
	{
		del = i;
		i = i->next;
		free(del->line);
		free(del->variable);
		free(del->content);
		free(del);
	}
	free(env);
	env = NULL;
}

void	free_pars_list(t_pars_list *parser)
{
	t_pars_node	*del;
	t_pars_node	*i;

	if (!parser)
		return ;
	i = parser->head;
	while (i)
	{
		del = i;
		i = i->next;
		free(del->content);
		free(del);
	}
	free(parser);
	parser = NULL;
}
