/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_for_pipex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:47:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/02 18:47:31 by dyoula           ###   ########.fr       */
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
		if (parse[i])
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
		if (node->type == 18)
		{
			delimiters[i] = ft_strdup(node->content);
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
