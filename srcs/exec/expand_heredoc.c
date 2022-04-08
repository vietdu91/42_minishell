/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:27:18 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/08 19:01:28 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*what_value_(char *str, t_env_list *env)
{
	char	**cpy;

	if (!str)
		return ;
	cpy = &str;
	where_is_dollar(cpy, env);
	convert_expand_quotes(parser);
	return (cpy) ;
}

int	modify_heredoc(char *hdoc, char *limitator)
{
	// 1 splitter par les \n 
	// checker chaque tab 
	// if $ agir comme fonction expand
	// checker si le limitator a des quotes
	return (0);
}
