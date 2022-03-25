/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:10:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/25 14:26:16 by dyoula           ###   ########.fr       */
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
	// char *str = line;
	
	// int i = -1;
	// while (str[++i])
	// 	printf("str[i] %d\n", str[i]);
	if (line[0] == 0)
		return (-1);
	cpy = &line;
	// printf("parsing maestro line = %s\n", line);
	parser(cpy, args->parser, args->env, args);
	return (0);
}
