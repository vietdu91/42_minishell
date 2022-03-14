/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribution_meta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:53:59 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/14 18:26:05 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
int	attribution_metachar(t_pars_node *node)
{
	if (!ft_strcmp(node->content, "<"))

		node->type = INPUT;
	else if (!ft_strcmp(node->content, "<<"))
		node->type = HEREDOC;
	else if (!ft_strcmp(node->content, ">"))
		node->type = OUTPUT;
	else if (!ft_strcmp(node->content, ">>"))
		node->type = SUPER_OUTPUT;
	else if (!ft_strcmp(node->content, "|"))
		node->type = PIPE;
	else if (!ft_strcmp(node->content, "||"))
		node->type = DOUBLE_PIPE;
	else if (!ft_strcmp(node->content, "&&"))
		node->type = LOGICAL_AND;
	else if (!ft_strcmp(node->content, "*"))
		node->type = ASTERISQUE;
	else if (!ft_strcmp(node->content, ";"))
		node->type = CONTINUE;
	return (0);
}

int	find_if_error(t_pars_node *node)
{
	if (is_meta(node->content[0]))
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
		else if (!ft_strcmp(node->content, "&&"))
			return (1);
		else if (!ft_strcmp(node->content, "*"))
			return (1);
		else if (!ft_strcmp(node->content, ";"))
			return (1);
		else
			node->type = EMPTY;
	}
	return (0);
}

int	check_if_meta(t_pars_list *l)
{
	t_pars_node	*i;

	i = l->head;
	while (i)
	{
		attribution_metachar(i);
		find_if_error(i);
		i = i->next;
	}
	return (0);
}

int	attribute_meta(t_pars_node *node)
{
	if (!ft_strcmp(node->content, "<") && apply_type(INPUT, node) \
		&& node->previous)
	{
		node->previous->type = CMD;
		if (!node->next)
			return (0);
		node->next->type = INFILE;
	}
	else if (!ft_strcmp(node->content, "<<") && apply_type(HEREDOC, node) && node->next)
		norm_heredoc(node);
	else if (!ft_strcmp(node->content, ">") && apply_type(OUTPUT, node) \
	&& node->next != NULL)
		node->next->type = OUTFILE;
	else if (!ft_strcmp(node->content, ">>") && apply_type(SUPER_OUTPUT, node) \
	&& node->next)
		node->next->type = SUPER_OUTFILE;
	else if (!ft_strcmp(node->content, "|") && apply_type(PIPE, node))
		apply_cmd(node, PIPE);
	else if (!ft_strcmp(node->content, "||") && apply_type(DOUBLE_PIPE, node))
		apply_cmd(node, DOUBLE_PIPE);
	else if (!ft_strcmp(node->content, "&&") && apply_type(LOGICAL_AND, node))
		apply_cmd(node, LOGICAL_AND);
	else if (is_full_meta(node->content) && !does_meta_exist(node))
		node->type = WRONG_META;
	return (0);
}

int	logical_attribution(t_pars_list *l)
{
	t_pars_node	*i;

	i = l->head;
	while (i)
	{
		attribute_meta(i);
		i = i->next;
	}
	return (0);
}
