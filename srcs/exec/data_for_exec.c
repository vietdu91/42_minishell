/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_for_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:58:40 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/06 03:11:29 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	read_heredoc(char *heredoc, char *del)
{
	char		buf[2];
	char		*txt;

	heredoc = ft_strdup("");
	txt = ft_strdup("");
	if (!txt || !heredoc)
		return (0);
	while (read(0, buf, 1) > 0)
	{
		buf[1] = 0;
		txt = ft_strjoin(txt, buf);
		if (strchr(txt, '\n'))
		{
			if (ft_strncmp(txt, del, ft_strlen(txt) - 1) == 0)
			{
				free(txt);
				return (1);
			}
			heredoc = ft_strjoin(heredoc, txt);
			if (!heredoc)
				return (0);
			free(txt);
			txt = ft_strdup("");
			if (!txt)
				return (0);
		}
	}
	free(txt);
	return (0);
}

int	size_d_tab(t_pars_list *l)
{
	int			i;
	t_pars_node	*node;

	node = l->head;
	i = 0;
	while (node)
	{
		if (node->type == CMD)
			i++;
		node = node->next;
	}
	return (i);
}

int	count_options(t_pars_node *cpy)
{
	t_pars_node	*node;
	int i;

	i = 0;
	if (!cpy->next)
		return (i);
	node = cpy->next;
	while (node && (node->type == OPTION || node->type == SIMPLE_ARG))
	{
		i++;
		node = node->next;
	}
	return (i);
}

int	*fill_index(t_pars_list *l)
{
	int			i;
	int			size;
	t_pars_node	*node;
	int			*index;

	size = size_d_tab(l);
	if (size == 0)
		return (NULL);
	index = malloc(sizeof(int) * (size));
	if (!index)
		return (NULL);
	node = l->head;
	i = 0;
	while (node)
	{
		if (node->type == CMD)
		{
			index[i] = count_options(node) + 1;
			i++;	
		}
		node = node->next;
	}
	return (index);
}

void	check_cmds(t_pars_list *l)
{
	t_pars_node	*node;

	node = l->head;
	while (node)
	{
		if (node->type == CMD)
		{
			int i = -1;
			while (node->cmds[++i])
				printf("cmds = %s\n", node->cmds[i]);
		}
		node = node->next;
	}
}

int	exec_maestro(t_args *args)
{
	int		n_docs;
	int		*index;
	t_pars_list	*l;

	l = args->parser;
	// (void)l;
	args->env_tab = init_env_tab(args->env);
	n_docs = count_heredoc(args->parser);
	args->delimiters = delimiters_to_tab(args->parser, n_docs);
	fill_d_tab_heredoc(args, n_docs, args->delimiters);
	index = fill_index(args->parser);
	iter_tab(args->parser, index);
	path_maestro(args);
	simple_exec(args, l);
	return (0);
}
