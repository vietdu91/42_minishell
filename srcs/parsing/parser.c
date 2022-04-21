/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:10:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/21 17:29:34 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	zap_spaces(char **line)
{
	int	i;

	i = 0;
	while (is_space(**line))
	{
		i++;
		(*line)++;
	}
	return (i);
}

int	encrypting(char *str, t_pars_node *parser)
{
	int	size;

	size = find_meta_in_quotes(str);
	if (!size)
		return (0);
	parser->index_crypted = ft_calloc(size, sizeof(int));
	fill_crypt_tab(str, parser);
	crypt_content(str, size, parser);
	return (size);
}

int	parser(char **line, t_pars_list *psr, t_env_list *env, t_args *args)
{
	int	i;
	int	len;

	if (!*line)
		return (0);
	len = ft_strlen(*line);
	i = 0;
	i += zap_spaces(line);
	while (**line && i < len)
	{
		i += zap_spaces(line);
		i += find_word(line, psr);
		i += zap_spaces(line);
		if (word_has_meta(psr->tail->content))
			cut_content(psr, env, args);
		else
		{
			expand(psr->tail->content, psr->tail, env);
			convert_content_without_quotes(psr->tail->content, psr->tail);
			encrypting(psr->tail->content, psr->tail);
		}
	}
	return (0);
}

int	parsing_maestro(t_args *args, char *line)
{
	char	**cpy;

	cpy = NULL;
	if (line[0] == 0)
		return (-1);
	cpy = &line;
	parser(cpy, args->parser, args->env, args);
	return (0);
}
