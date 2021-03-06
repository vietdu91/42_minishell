/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribution_meta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:53:59 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/09 16:12:49 by emtran           ###   ########.fr       */
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
	if (!ft_strcmp(node->content, "<") && apply_type(INPUT, node))
	{
		if (!node->next)
			return (0);
		node->next->type = INFILE;
	}
	else if (!ft_strcmp(node->content, "<<") && apply_type(HEREDOC, node) \
	&& node->next)
		norm_heredoc(node);
	else if (!ft_strcmp(node->content, ">") && apply_type(OUTPUT, node) \
	&& node->next != NULL)
		node->next->type = OUTFILE;
	else if (!ft_strcmp(node->content, ">>") && apply_type(SUPER_OUTPUT, node) \
	&& node->next)
		node->next->type = SUPER_OUTFILE;
	else if (!ft_strcmp(node->content, "|"))
		apply_type(PIPE, node);
	else if (is_full_meta(node->content) && !does_meta_exist(node))
		node->type = WRONG_META;
	return (0);
}

int	logical_attribution(t_pars_list *l)
{
	t_pars_node	*i;
	int			file;

	file = 0;
	i = l->head;
	while (i)
	{
		attribute_meta(i);
		i = i->next;
	}
	i = l->head;
	while (i)
	{
		if (i->type == PIPE)
			file = 0;
		if (i && (i->type == OUTFILE \
			|| i->type == SUPER_OUTFILE))
			file = 1;
		if (file == 1 && i->content[0] == '-' && i->content[1] != 0)
				i->type = OPTION;
		i = i->next;
	}
	return (0);
}
