/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:10:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/21 12:15:12 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

**        ls > infile1 infile 2 
**
*/
void	zap_spaces(char **line)
{
	while (is_space(**line))
		(*line)++;
}

char	*first_word(char **str)
{
	int		i;
	char	*cpy;
	char	*content;

	i = 0;
	cpy = *str;
	while (cpy[i] && !is_space(cpy[i]))
		i++;
	content = malloc(sizeof(char) * (i + 1));
	if (!content)
		return (NULL);
	i = 0;
	while (**str && !is_space(**str))
	{
		content[i] = **str;
		i++;
		(*str)++;
	}
	content[i] = 0;
	printf("first word = %s\n", content);
	return (content);
}

int	parser(char **line)
{
	zap_spaces(line);
	// checker chevron 
	first_word(line);
	// printf("je suis line %s\n", *line);
	return (0);
}

int	maestro(char *line)
{
	char	**cpy;

	cpy = &line;
	printf("cpy = %s\n", *cpy);
	parser(cpy);
	return (0);
}
