/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:10:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/04 15:05:02 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

**        ls > infile1 infile 2 
**
*/
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

int	parser(char **line, t_pars_list *parser, t_args *args)
{
	int		i;
	int		len;

	if (!*line)
		return (0);
	len = ft_strlen(*line);
	i = 0;
	i += zap_spaces(line);
	while (**line && i < len)
	{
		i += zap_spaces(line);
		i += find_word(line, parser);
		i += zap_spaces(line);
		if (word_has_meta(parser->tail->content))
			cut_content(parser, args);
	}
	return (0);
}

int	maestro(t_args *args, char *line)
{
	char	**cpy;

	cpy = &line;
	parser(cpy, args->parser, args);
	display_parsing(args->parser);
	return (0);
}
