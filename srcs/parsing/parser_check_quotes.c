/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:07:12 by emtran            #+#    #+#             */
/*   Updated: 2022/05/06 16:53:11 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*check_quotes_in_content(char *content, t_pars_node *node)
{
	int		a;
	char	*str;

	a = 0;
	str = malloc(sizeof(char) * (ft_strlen(content) + 1));
	while (content[a])
	{
		if (is_quote(content[a]) == 1)
		{
			str[a] = 6;
			node->check_in = TRUE;
		}
		else if (is_quote(content[a]) == 2)
		{
			str[a] = 8;
			node->check_in = TRUE;
		}
		else
			str[a] = content[a];
		a++;
	}
	str[a] = 0;
	free(content);
	return (str);
}

char	*decheck_quotes_in_content(char *content)
{
	int		a;
	char	*str;

	a = 0;
	str = ft_calloc(ft_strlen(content) + 1, sizeof(char));
	while (content[a])
	{
		if (str[a] == 6)
			str[a] = '\'';
		else if (content[a] == 8)
			str[a] = '\"';
		else
			str[a] = content[a];
		a++;
	}
	str[a] = 0;
	free(content);
	return (str);
}
