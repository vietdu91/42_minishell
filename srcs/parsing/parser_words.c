/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:22:39 by emtran            #+#    #+#             */
/*   Updated: 2022/01/31 21:35:13 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cut_content(t_pars_list *l, int size)
{
	int		i;
	char	**splitted;

	(void)size;
	splitted = ft_split_charset(l->tail->content, METACHAR);
	i = -1;
	while (splitted[++i])
		printf("%s\n", splitted[i]);
	return (0);
}

int	word_has_meta(t_pars_list *l, int *meta)
{
	int	i;
	// int	quote_seen;
	int quote_counter;

	(void)meta;
	i = -1;
	quote_counter = 0;
	while (is_meta(l->tail->content[++i]))
		list_end_parse(l, l->tail->content[i])
	i = -1;
	while (l->tail->content[++i])
	{
		if (is_quote(l->tail->content[i]))
		{
			printf("coucou\n");
			quote_counter++;
		}
		printf("QUOTE : %d\n", quote_counter);
		if (is_meta(l->tail->content[i]) && quote_counter != 1)
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
	printf("first word = %s\n", content);
	list_end_parse(parser, content);
	return (i);
}
