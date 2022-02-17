/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:10:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/14 17:23:45 by emtran           ###   ########.fr       */
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

int	parser(char **line, t_pars_list *psr, t_env_list *env, t_args *args)
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
		i += find_word(line, psr);
		i += zap_spaces(line);
		if (word_has_meta(psr->tail->content))
			cut_content(psr, env, args);
		else
		{
			expand(psr->tail->content, psr->tail, env);
			convert_content_without_quotes(&psr->tail->content, psr->tail);
			encrypting(psr->tail->content, psr->tail);
		}
	}
	return (0);
}

int	parsing_maestro(t_args *args, char *line)
{
	char	**cpy;

	cpy = &line;
	parser(cpy, args->parser, args->env, args);
	// display_parsing(args->parser);
	return (0);
}
