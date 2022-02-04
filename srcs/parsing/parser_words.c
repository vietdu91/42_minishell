/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:22:39 by emtran            #+#    #+#             */
/*   Updated: 2022/02/04 17:02:13 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cut_content(t_pars_list *l, t_args *args)
{
	int			i;
	char		**splitted;

	splitted = NULL;
	splitted = ft_split_charset(splitted, l->tail->content, METACHAR, args);
	if (!splitted)
		return (0);
	i = 0;
	free(l->tail->content);
	l->tail->content = NULL;
	l->tail->content = ft_strdup(splitted[0]);
	while (splitted[++i])
		list_end_parse(l, splitted[i]);
	free_d_tab(splitted);
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
	int	count;

	i = 0;
	count = 0;
	while (str[i] && !is_space(str[i]))
	{
		if (str[i] == '\"')
			return (check_len_word_in_quotes('\"', str, i, count));
		else if (str[i] == '\'')
			return (check_len_word_in_quotes('\'', str, i, count));
		i++;
		count++;
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
			break ;
		}
		else if (**str == '\'')
		{
			content[i++] = *(*str)++;
			while (**str != '\'')
				content[i++] = *(*str)++;
			content[i++] = *(*str)++;
			break ;
		}
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
	printf("word = %s\n", content);
	list_end_parse(parser, content);
	free(content);
	return (i);
}
