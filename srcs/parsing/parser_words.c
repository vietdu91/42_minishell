/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:22:39 by emtran            #+#    #+#             */
/*   Updated: 2022/02/13 17:09:00 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cut_content(t_pars_list *parser, t_args *args)
{
	int			i;
	char		**splitted;

	splitted = NULL;
	splitted = ft_split_charset(splitted, parser->tail->content, METACHAR, \
	args);
	if (!splitted)
		return (0);
	i = 0;
	free(parser->tail->content);
	parser->tail->content = NULL;
	parser->tail->content = ft_strdup(splitted[0]);
	expand(parser->tail->content, parser->tail, args);
	convert_content_without_quotes(&parser->tail->content, parser->tail);
	encrypting(parser->tail->content, parser->tail);
	while (splitted[++i])
	{
		list_end_parse(parser, splitted[i]);
		expand(parser->tail->content, parser->tail, args);
		convert_content_without_quotes(&parser->tail->content, parser->tail);
		encrypting(parser->tail->content, parser->tail);
	}
	free_d_tab(splitted);
	return (0);
}

int	word_has_meta(char *content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (is_quote(content[i]) == 1)
		{
			i++;
			while (content[i] != '\'')
				i++;
		}
		else if (is_quote(content[i]) == 2)
		{
			i++;
			while (content[i] != '\"')
				i++;
		}
		else if (is_meta(content[i]))
			return (1);
		i++;
	}
	return (0);
}

int	check_len_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && !is_space(str[i]))
	{
		if (str[i] == '\"')
			count = check_len_word_in_quotes('\"', str, &i, count);
		else if (str[i] == '\'')
			count = check_len_word_in_quotes('\'', str, &i, count);
		else
		{
			i++;
			count++;
		}
	}
	return (count);
}

char	*put_word_to_content(char **str, char *content)
{
	int		i;

	i = 0;
	while (**str && !is_space(**str))
	{
		if (**str == '\"')
		{
			content[i++] = *(*str)++;
			while (**str != '\"')
				content[i++] = *(*str)++;
			content[i++] = *(*str)++;
		}
		else if (**str == '\'')
		{
			content[i++] = *(*str)++;
			while (**str != '\'')
				content[i++] = *(*str)++;
			content[i++] = *(*str)++;
		}
		else
			content[i++] = *(*str)++;
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
	list_end_parse(parser, content);
	free(content);
	return (i);
}
