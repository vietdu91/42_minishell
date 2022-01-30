/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:10:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/30 20:47:09 by dyoula           ###   ########.fr       */
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
	while (is_space(*line[i]))
	{
		i++;
		(*line)++;
	}
	return (i);
}

int	first_word(char **str, t_parsing_list *l)
{
	int		i;
	char	*cpy;
	char	*content;

	i = 0;
	cpy = *str;
	zap_spaces(&cpy);
	while (cpy[i] && !is_space(cpy[i]))
	{
		// printf("i de fw = %d\n", i);
		i++;
	}
	content = malloc(sizeof(char) * (i + 1));
	if (!content)
		return (0);
	i = 0;
	while (**str && !is_space(**str))
	{
		// printf("lettre %c", **str);
		content[i] = **str;
		i++;
		(*str)++;
	}
	content[i] = 0;
	printf("first word = %s\n", content);
	(void)l;
	list_end_parse(l, content);
	return (i);
}

int	parser(char **line, t_parsing_list *l)
{
	int	i;
	int	len;

	len = ft_strlen(*line);
	i = 0;
	i += zap_spaces(line);
	while (**line && i < len)
	{
		i += zap_spaces(line);
		i += first_word(line, l);
	}
	// first_word(line);
	// checker chevron
	return (0);
}

int	maestro(char *line)
{
	char			**cpy;
	t_parsing_list	*l;

	l = NULL;
	init_parsing_list(&l);
	cpy = &line;
	parser(cpy, l);
	display_parsing(l);
	return (0);
}
