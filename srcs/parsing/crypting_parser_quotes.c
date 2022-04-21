/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypting_parser_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:59:40 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/21 17:29:13 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	delete_bool_quotes(int *i, char *str, int *quotes, char type_quote)
{
	if (str[*i] == type_quote && *quotes == 1)
		(*quotes)--;
}

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
		delete_bool_quotes(i, str, quotes, '\"');
	}
	else if (str[i] == '\'' && quotes == 0)
	{
		quotes++;
		i++;
		while (str[i++] != '\'')
			if (is_meta(str[i]) && quotes == 1)
				parser->index_crypted[(*j)++] = i;
		delete_bool_quotes(i, str, quotes, '\'');
	}
	else
		i++;
	return (i);
}

int	fill_crypt_tab(char *str, t_pars_node *parser)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] && i < ft_strlen(str))
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
