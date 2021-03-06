/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:06:17 by emtran            #+#    #+#             */
/*   Updated: 2022/04/26 17:26:22 by dyoula           ###   ########.fr       */
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
		free(del->content_trim);
		free(del);
	}
	free(env);
	env = NULL;
}

void	delete_pars_node_list(t_pars_node *del)
{
	free(del->content);
	if (del->nw_content)
		free(del->nw_content);
	if (del->content_exp)
		free(del->content_exp);
	if (del->content_exp_sans_q)
		free(del->content_exp_sans_q);
	if (del->index_crypted)
		free(del->index_crypted);
	if (del->cmds)
		free_d_tab(del->cmds);
	if (del->path)
		free(del->path);
	free(del);
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
		delete_pars_node_list(del);
	}
	free(parser);
	parser = NULL;
}
