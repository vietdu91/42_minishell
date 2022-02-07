/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:10:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/07 19:55:02 by emtran           ###   ########.fr       */
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

	(void) args;
	if (!*line)
		return (0);
	len = ft_strlen(*line);
	i = 0;
	i += zap_spaces(line);
	while (**line && i < len)
	{
		i += zap_spaces(line);
	//	printf("LINE = %s\n", *line);
		i += find_word(line, parser);
		i += zap_spaces(line);
		printf("JE PASSE... : %s\n", parser->tail->content);
		if (word_has_meta(parser->tail->content))
			cut_content(parser, args);
	//	printf("CONTENT = %s\n", parser->tail->content);
		else
		{
			printf("PAR LA ?... : %s\n", parser->tail->content);
			convert_content_without_quotes(&parser->tail->content, parser->tail);
			encrypting(parser->tail->content, parser->tail);
		}
	}
	return (0);
}

int	maestro(t_args *args, char *line)
{
	char	**cpy;

	cpy = &line;
	parser(cpy, args->parser, args);
	check_if_meta(args->parser);
	logical_attribution(args->parser);
	display_parsing(args->parser);
	return (0);
}
