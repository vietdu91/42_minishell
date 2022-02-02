/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:22:39 by emtran            #+#    #+#             */
/*   Updated: 2022/02/02 20:52:41 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	while_is_meta(t_pars_list *l, char *str, int i)
{
	char	c[2];
	char	*cpy;

	c[1] = 0;
	cpy = NULL;
	if (str[i] && is_meta(str[i]))
	{
		c[0] = str[i];
		cpy = ft_strdup(str + 1);
		free(l->tail->content);
		l->tail->content = NULL;
		l->tail->content = ft_strdup(c);
		i++;
	}
	list_end_parse(l, cpy);
	free(cpy);
	cpy = NULL;
	return (i);
}

int	while_isnt_meta(t_pars_list *l, char *str, int i)
{
	char	*c;

	c = ft_strdup("");
	if (!str)
		return (0);
	while (str[i] && !is_meta(str[i]))
	{
		c = join_char(c, str[i]);
		printf("salut %s\n", c);
		i++;
	}
	list_end_parse(l, c);
	free(c);
	return (i);
}

int	cut_content(t_pars_list *l)
{
	int			i;
//	char		*cpy;
//	t_pars_node	*node;
	char		**splitted;

	splitted = ft_split_charset(l->tail->content, METACHAR);
	i = -1;
	while (splitted[++i])
	{
		printf("CONTENT : %s\n", l->tail->content);
		list_end_parse(l, splitted[i]);
		printf("SPLIT : %s\n", splitted[i]);
	}
/*	i = 0;
	node = l->tail;
	cpy = ft_strdup(l->tail->content);
	while (cpy[i] && node)
	{
		while (while_is_meta(l, node->content, i))
			i++;
		printf("first i = %d\n", i);
		node = l->tail;
		printf("je disparais %s\n", node->content);
		i += while_isnt_meta(l, node->content, i);
		printf("second i = %d\n", i);
		node = l->tail;
	}*/
	free_d_tab(splitted);
//	free(cpy);
	return (0);
}

int	word_has_meta(char *content)
{
	int	i;
	int	quote_counter;

	i = -1;
	quote_counter = 0;
	while (content[++i])
	{
		if (is_quote(content[i]))
			quote_counter++;
		if (quote_counter == 2)
			quote_counter = 0;
		if (is_meta(content[i]) && (quote_counter % 2) == 0)
			return (1);
	}
	return (0);
}

int	check_len_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !is_space(str[i]))
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"')
				i++;
		}
		else if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'')
				i++;
		}
		i++;
	}
	return (i);
}

char	*put_word_to_content(char **str, char *content)
{
	int	i;

	i = 0;
	while (**str && !is_space(**str))
	{
		if (**str == '\"')
		{
			content[i] = **str;
			i++;
			(*str)++;
			while (**str != '\"')
			{
				content[i] = **str;
				i++;
				(*str)++;
			}
		}
		else if (**str == '\'')
		{
			content[i] = **str;
			i++;
			(*str)++;
			while (**str != '\'')
			{
				content[i] = **str;
				i++;
				(*str)++;
			}
		}
		content[i] = **str;
		i++;
		(*str)++;
	}
	content[i] = 0;
	return (content);
}

int	find_word(char **str, t_pars_list *parser)
{
	int		i;
	char	*cpy;
	char	*content;

	i = 0;
	cpy = *str;
	zap_spaces(&cpy);
	i = check_len_word(cpy);
	content = malloc(sizeof(char) * (i + 1));
	if (!content)
		return (0);
	content = put_word_to_content(str, content);
	printf("word = %s\n", content);
	list_end_parse(parser, content);
	free(content);
	return (i);
}
