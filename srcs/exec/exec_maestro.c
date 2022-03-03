/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_maestro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:58:40 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/03 17:13:44 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

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
	return (i * 2);
}


int	*fill_index(t_pars_list *l)
{
	int			i;
	int			j;
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
		j = 0;
		if (node->type == CMD)
		{
			index[i++] = j++;
			if (node->next)
				node = node->next;
		}
		j = 0;
		while (node && node->type == OPTION && node->next)
		{
			j++;
			node = node->next;
		}
		index[i++] = j++;
		if (!node->next)
			return (index);
		node = node->next;
	}
	return (index);
}

void	count_option(t_pars_node *cpy, int *index, int position)
{
	int			i;
	t_pars_node	*node;

	if (!index)
		return ;
	if (!cpy->next)
		return ;
	node = cpy->next;
	i = 0;
	while (node && node->type == OPTION)
	{
		i++;
		node = node->next;
	}
	index[position] = i;
}

char	**cmd_into_list(t_pars_list *l, int	*index)
{
	t_pars_node	*node;
	int			i;

	i = 0;
	node = l->head;
	// utiliser tableau et lister les index des otpions et des cmd 
	while (node)
	{
		if (node->type == CMD)
		{
			count_option(node, index, i);
			i++;
		}
		node = node->next;
	}
	return (NULL);
}


int	exec_maestro(t_args *args)
{
	t_exec	exec;
	int		*index;
	int		size;

	exec.env = init_env_tab(args->env);
	exec.hdocs = count_heredoc(args->parser);
	exec.delimiters = delimiters_to_tab(args->parser, exec.hdocs);
	exec.args = args;
	fill_d_tab_heredoc(&exec, exec.hdocs, exec.delimiters);
	// cmd to linked list
	size = size_d_tab(args->parser) / 2;
	printf("HOLA\n");
	index = fill_index(args->parser);
	int i = 0;
	while (i < size * 2)
	{
		printf("index[%d] == %d\n", i, index[i]);
		i++;
	}
	// exec.cmds = init_list();
	return (0);
}
