/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:10:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/31 21:01:24 by dyoula           ###   ########.fr       */
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

int	parser(char **line, t_pars_list *parser)
{
	int	i;
	int	len;
	int	meta;

	meta = 0;
	if (!*line)
		return (0);
	len = ft_strlen(*line);
	i = 0;
	i += zap_spaces(line);
	while (**line && i < len)
	{
		i += zap_spaces(line);
		i += find_word(line, parser);
		if (word_has_meta(parser, &meta))
			cut_content(parser, meta);
	}
	return (0);
}

int	maestro(t_args *args, char *line)
{
	char			**cpy;

	cpy = &line;
	parser(cpy, args->parser);
	display_parsing(args->parser);
	return (0);
}
