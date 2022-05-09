/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:45:46 by emtran            #+#    #+#             */
/*   Updated: 2022/05/09 11:07:04 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*put_new_word_to_content(char **str, \
char *content)
{
	int		i;

	i = 0;
	while (**str && !is_space(**str))
	{
		if (**str == '\"')
		{
			(*str)++;
			while (**str != '\"')
				content[i++] = *(*str)++;
			(*str)++;
		}
		else if (**str == '\'')
		{
			(*str)++;
			while (**str != '\'')
				content[i++] = *(*str)++;
			(*str)++;
		}
		else
			content[i++] = *(*str)++;
	}
	content[i] = 0;
	return (content);
}

int	check_len_nw_word_in_quotes(char quote, char *str, int *pos, int count)
{
	(*pos)++;
	while (str[*pos] != quote)
	{
		(*pos)++;
		count++;
	}
	(*pos)++;
	return (count);
}

int	check_len_new_word(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			count = check_len_nw_word_in_quotes('\"', str, &i, count);
		else if (str[i] == '\'')
			count = check_len_nw_word_in_quotes('\'', str, &i, count);
		else
		{
			i++;
			count++;
		}
	}
	return (count);
}

void	convert_content_without_quotes(char *str, t_pars_node *parser)
{
	int		i;
	char	*cpy;

	cpy = str;
	i = check_len_new_word(cpy);
	parser->nw_content = malloc(sizeof(char) * (i + 1));
	if (!parser->nw_content)
		return ;
	parser->nw_content = put_new_word_to_content(&cpy, parser->nw_content);
}
