/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_for_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:58:40 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/26 18:23:18 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	join_heredoc(char **heredoc, char *txt, char *del)
// {

// 	return (0);
// }

int	read_heredoc(char **heredoc, char *del)
{
	char		buf[2];
	char		*txt;

	buf[0] = 0;
	*heredoc = ft_strdup("");
	txt = ft_strdup("");
	if (!txt || !(*heredoc))
		return (0);
	while (read(0, buf, 1) > 0)
	{
		buf[1] = 0;
		txt = ft_strjoin(txt, buf);
		if (strchr(txt, '\n'))
		{
			if (!ft_strncmp(txt, del, (ft_strlen(txt) + 1)))
			{
				free(txt);
				return (1);
			}
			// printf("join heredoc = %s\n", *heredoc);
			*heredoc = ft_strjoin(*heredoc, txt);
			// printf("join heredoc = %s\n", *heredoc);
			if (!(*heredoc))
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

void	check_cmds(t_pars_list *l)
{
	t_pars_node	*node;
	int			i;

	node = l->head;
	while (node)
	{
		if (node->type == CMD)
		{
			i = -1;
			while (node->cmds[++i])
				printf("cmds = %s\n", node->cmds[i]);
		}
		node = node->next;
	}
}

// acces au eof via le parser Trouver le bon limitator.

int	exec_maestro(t_args *args)
{
	int			n_docs;
	t_pars_list	*l;

	l = args->parser;
	args->env_tab = init_env_tab(args->env);
	n_docs = count_heredoc(args->parser);
	args->delimiters = delimiters_to_tab(args->parser, n_docs, args);
	fill_d_tab_heredoc(args, n_docs, args->delimiters);
	modify_heredoc(args->hdocs, args->del_for_split, args->env);
	options_maestro(args, l);
	path_maestro(args);
	inf_out_maestro(args, l);
	loop_execution(args, l);
	free_d_tab(args->env_tab);
	args->env_tab = NULL;
	free_d_tab(args->delimiters);
	args->delimiters = NULL;
	return (0);
}
