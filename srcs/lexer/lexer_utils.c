/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:50:38 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/03 11:16:50 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*cut_path(char *str, char *no_space)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] <= 9 || str[i] >= 13) && str[i] != ' ')
		i++;
	no_space = malloc(sizeof(char) * (i + 1));
	if (!no_space && no_space)
		return (NULL);
	while (j < i)
	{
		no_space[j] = str[j];
		j++;
	}
	no_space[j] = 0;
	return (no_space);
}

int	check_enum(int n)
{
	const int	meta[] = {11, 13, 15, 17};
	int			i;

	i = -1;
	while (++i < 4)
		if (meta[i] == n)
			return (1);
	return (0);
}

void	norm_heredoc(t_pars_node *node)
{
	if (!node)
		return ;
	if (!node->next)
		return ;
	node->next->type = LIMITATOR;
	printf("hello\n");
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
//	printf("node->content %s\n", node->content);
	return (0);
}

int	forbidden_token(t_pars_list *l)
{
	t_pars_node	*i;

	i = l->head;
	while (i && i->next)
	{
		if (does_meta_exist(i) && is_forbidden(i->next))
		{
			ft_putstr("syntax error near unexpected token '", 2);
			ft_putstr(i->next->content, 2);
			ft_putstr("'\n", 2);
			return (1);
		}
		i = i->next;
	}
	return (0);
}
