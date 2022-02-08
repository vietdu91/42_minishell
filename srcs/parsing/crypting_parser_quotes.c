/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypting_parser_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:59:40 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/08 18:01:36 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	prepare_crypt(int i, int *j, char *str, t_pars_node *parser)
{
	int	quotes;

	quotes = 0;
	if (str[i] == '\"' && quotes == 0)
	{
		quotes++;
		i++;
		while (str[i++] != '\"')
			if (is_meta(str[i]) && quotes == 1)
				parser->index_crypted[(*j)++] = i;
		if (str[i] == '\"' && quotes == 1)
			quotes--;
	}
	else if (str[i] == '\'' && quotes == 0)
	{
		quotes++;
		i++;
		while (str[i++] != '\'')
			if (is_meta(str[i]) && quotes == 1)
				parser->index_crypted[(*j)++] = i;
		if (str[i] == '\'' && quotes == 1)
			quotes--;
	}
	return (i);
}

int	fill_crypt_tab(char *str, t_pars_node *parser)
{
	int	i;
	int	quotes;
	int	j;

	j = 0;
	i = 0;
	quotes = 0;
	while (str[i])
		i = prepare_crypt(i, &j, str, parser);
	return (0);
}

void	crypt_content(char *str, int size, t_pars_node *parser)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[parser->index_crypted[i]] == '|')
			str[parser->index_crypted[i]] = '0';
		else if (str[parser->index_crypted[i]] == '&')
			str[parser->index_crypted[i]] = '1';
		else if (str[parser->index_crypted[i]] == ';')
			str[parser->index_crypted[i]] = '2';
		else if (str[parser->index_crypted[i]] == '<')
			str[parser->index_crypted[i]] = '3';
		else if (str[parser->index_crypted[i]] == '>')
			str[parser->index_crypted[i]] = '4';
		i++;
	}
}

void	decrypt_content(char *str, int size, t_pars_node *parser)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[parser->index_crypted[i]] == '0')
			str[parser->index_crypted[i]] = '|';
		else if (str[parser->index_crypted[i]] == '1')
			str[parser->index_crypted[i]] = '&';
		else if (str[parser->index_crypted[i]] == '2')
			str[parser->index_crypted[i]] = ';';
		else if (str[parser->index_crypted[i]] == '3')
			str[parser->index_crypted[i]] = '<';
		else if (str[parser->index_crypted[i]] == '4')
			str[parser->index_crypted[i]] = '>';
		i++;
	}
}

int	encrypting(char *str, t_pars_node *parser)
{
	int	i;
	int	j;
	int	size;

	j = 0;
	i = -1;
	size = find_meta_in_quotes(str);
	if (!size)
		return (0);
	parser->index_crypted = ft_calloc(size, sizeof(int));
	fill_crypt_tab(str, parser);
	crypt_content(str, size, parser);
	return (0);
}
