/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:30:47 by emtran            #+#    #+#             */
/*   Updated: 2022/04/21 12:31:25 by emtran           ###   ########.fr       */
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
