/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_for_pipex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:47:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/15 02:48:33 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**init_env_tab(t_env_list *l)
{
	t_env	*node;
	char	**env;
	int		i;

	node = l->head;
	env = malloc(sizeof(char *) * (l->length + 1));
	if (!env)
		return (NULL);
	i = 0;
	while (node)
	{
		env[i] = ft_strdup(node->line);
		if (!env[i])
		{
			malloc_failed(env, i);
			return (NULL);
		}
		i++;
		node = node->next;
	}
	env[i] = NULL;
	return (env);
}

char	**init_parse_to_tab(t_pars_list *l)
{
	int			i;
	t_pars_node	*node;
	char		**parse;

	node = l->head;
	parse = malloc(sizeof(char *) * (l->length + 1));
	if (parse)
		return (NULL);
	i = 0;
	while (node)
	{
		parse[i] = ft_strdup(node->content);
		if (!parse[i])
		{
			malloc_failed(parse, i);
			return (NULL);
		}
		i++;
		node = node->next;
	}
	parse[i] = NULL;
	return (parse);
}

char	*remove_quotes_delimiters(char *str)
{
	int		i;
	int		j;
	int		size;
	char	*content;
	
	size = check_len_new_word(str);
	content = malloc(sizeof(char) * (size + 1));
	if (!content)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
				content[j++] = str[i++];
			i++;
		}
		else if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				content[j++] = str[i++];
			i++;
		}
		else
			content[j++] = str[i++];
	}
	content[j] = 0;
	return (content);
}

char	**delimiters_to_tab(t_pars_list *l, int size)
{
	int			i;
	t_pars_node	*node;
	char		**delimiters;

	delimiters = malloc(sizeof(char *) * (size + 1));
	if (!delimiters)
		return (NULL);
	i = 0;
	node = l->head;
	while (node)
	{
		if (node->type == LIMITATOR)
		{
			delimiters[i] = ft_strdup(remove_quotes_delimiters(node->content));
			if (!delimiters[i])
			{
				malloc_failed(delimiters, i);
				return (NULL);
			}
			i++;
		}
		node = node->next;
	}
	delimiters[i] = NULL;
	return (delimiters);
}

char	**content_to_d_tab(int iter, int *index, t_pars_node *cpy)
{
	t_pars_node	*n;
	int			i;
	char		**d_tab;

	d_tab = malloc(sizeof(char *) * (index[iter] + 1));
	if (!d_tab)
		return (NULL);
	i = 0;
	n = cpy;
	while (i < index[iter])
	{
		d_tab[i++] = ft_strdup(n->content);
		if (!d_tab)
		{
			malloc_failed(d_tab, i);
			return (NULL);
		}
		n = n->next;
	}
	d_tab[i] = NULL;
	return (d_tab);
}
