/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:27:18 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/08 20:04:35 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	modify_heredoc(char *hdoc, char *limitator)
{
	// 1 splitter par les \n 
	// checker chaque tab 
	// if $ agir comme fonction expand
	// checker si le limitator a des quotes
	char	**d_tab;
	int		i;

	i = -1;
	// find which is the good limitator
	if (quotes_or_not(limitator))
		return (-1);
	d_tab = ft_split(hdoc, '\n');
	d_tab = NULL;
	if (d_tab)
		return (-1);
	
	while (d_tab[++i])
	{
		send_variable(d_tab[i], limitator, env);
		
	}
	return (0);
}

