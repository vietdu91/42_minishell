/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_for_exec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:58:40 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/17 19:21:30 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	free_txt_ndeal(char *new_deal, char *txt, int n)
{
	if (n == 1)
	{
		free(txt);
		free(new_deal);
		return (1);
	}
	else if (n == 2)
	{
		free(new_deal);
		return (0);
	}
	return (-1);
}

int	read_heredoc(char **heredoc, char *del)
{
	char		buf[2];
	char		*txt;
	char		*new_deal;
	int			ret;

	buf[0] = 0;
	*heredoc = ft_strdup("");
	txt = NULL;
	if (!(*heredoc))
		return (0);
	new_deal = NULL;
	new_deal = ft_strjoin_one_c_sans_free(del, '\n');
	while (read(0, buf, 1) > 0)
	{
		ret = boucle_heredoc(buf, &txt, new_deal, heredoc);
		if (ret < 2)
			return (ret);
	}
	free_txt_ndeal(new_deal, txt, 1);
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
	file_create_loop(args->parser);
	inf_out_maestro(args, l);
	loop_execution(args, l);
	free_d_tab(args->env_tab);
	args->env_tab = NULL;
	free_d_tab(args->delimiters);
	args->delimiters = NULL;
	return (0);
}
