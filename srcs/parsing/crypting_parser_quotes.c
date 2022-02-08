/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crypting_parser_quotes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 16:59:40 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/07 17:26:41 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	find_meta_in_quotes(char *str)
{
	int	i;
	int	quotes;
	int	encrypt;

	i = -1;
	quotes = 0;
	encrypt = 0;
	while (str[++i])
	{
		if (str[i] == '\"' && quotes == 0)
			quotes++;
		else if (str[i] == '\"' && quotes == 1)
			quotes--;
		if (is_meta(str[i]) && quotes == 1)
			encrypt++;
	}
	return (encrypt);
}

int	fill_crypt_tab(char *str, t_pars_node *parser)
{
	int	i;
	int	quotes;
	int	encrypt;
	int	j;

	j = 0;
	i = -1;
	quotes = 0;
	encrypt = 0;
	while (str[++i])
	{
		if (str[i] == '\"' && quotes == 0)
			quotes++;
		else if (str[i] == '\"' && quotes == 1)
			quotes--;
		if (is_meta(str[i]) && quotes == 1)
			parser->index_crypted[j++] = i;
	}
	return (0);
}

void	crypt_content(char *str, int size, t_pars_node *parser)
{
	int	i;

	i = -1;
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

	i = -1;
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
	parser->index_crypted = ft_calloc(1, sizeof(int));
	fill_crypt_tab(str, parser);
	crypt_content(str, size, parser);
	return (0);
}
