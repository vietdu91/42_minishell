/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:50:38 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/21 16:28:05 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_enum(int n)
{
	const int	meta[] = {6, 11, 13, 15, 17, 20};
	int			i;

	i = -1;
	while (++i < 6)
		if (meta[i] == n)
			return (1);
	return (0);
}

void	hdocs_is_valid(t_pars_node *node)
{
	t_pars_node	*i;

	i = node;
	while (i)
	{
		if (i->type == OUTFILE || i->type == SUPER_OUTFILE)
		{
			node->next->type = FAKE_HEREDOCS;
			return ;
		}
		i = i->previous;
	}
	return ;
}

void	norm_heredoc(t_pars_node *node)
{
	if (!node)
		return ;
	if (!node->next)
		return ;
	node->next->type = LIMITATOR;
	hdocs_is_valid(node);
	if (!node->next->next)
		return ;
	node->next->next->type = CMD;
}

int	is_forbidden(t_pars_node *node)
{
	if (!ft_strcmp(node->content, "<"))
		return (1);
	else if (!ft_strcmp(node->content, "<<"))
		return (1);
	else if (!ft_strcmp(node->content, ">"))
		return (1);
	else if (!ft_strcmp(node->content, ">>"))
		return (1);
	else if (!ft_strcmp(node->content, "|"))
		return (1);
	else if (!ft_strcmp(node->content, "||"))
		return (1);
	else if (!ft_strcmp(node->content, "&"))
		return (1);
	else if (!ft_strcmp(node->content, "&&"))
		return (1);
	else if (!ft_strcmp(node->content, ";"))
		return (1);
	return (0);
}

//	ft_putstr("syntax error near unexpected token '", 2);
//	ft_putstr(i->next->content, 2);
//	ft_putstr("'\n", 2);

int	forbidden_token(t_pars_list *l)
{
	t_pars_node	*i;

	i = l->head;
	while (i && i->next)
	{
		if (does_meta_exist(i) && is_forbidden(i->next))
			return (1);
		i = i->next;
	}
	return (0);
}
