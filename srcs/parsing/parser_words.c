/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 15:22:39 by emtran            #+#    #+#             */
/*   Updated: 2022/01/31 15:29:51 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
