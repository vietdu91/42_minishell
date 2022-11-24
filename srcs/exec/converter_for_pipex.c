/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_for_pipex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 14:47:16 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 16:16:41 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	str_to_content(char *str, char *content, int *i, int *j)
{
	(*i)++;
	while (str[*i] != '\"')
		content[(*j)++] = str[(*i)++];
	(*i)++;
}

char	*remove_quotes(char *str, char *content)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			str_to_content(str, content, &i, &j);
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

char	*remove_quotes_delimiters(char *str)
{
	int		size;
	char	*content;

	size = check_len_new_word(str);
	content = NULL;
	content = malloc(sizeof(char) * (size + 1));
	if (!content)
		return (NULL);
	content = remove_quotes(str, content);
	return (content);
}

char	**delimiters_to_tab(t_pars_list *l, int size, t_args *args)
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
			args->del_for_split = ft_strdup(node->content);
			delimiters[i] = remove_quotes_delimiters(node->content);
			if (return_delimiter_to_tab(delimiters, i))
				return (NULL);
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
