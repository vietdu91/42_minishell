/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_for_exec_norm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:34:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 18:55:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	boucle_heredoc(char buf[2], char *txt, char *new_deal, char **heredoc)
{
	buf[1] = 0;
	txt = ft_strjoin(txt, buf);
	if (ft_strchr(txt, '\n'))
	{
		if (!ft_strcmp(txt, new_deal))
			return (free_txt_ndeal(new_deal, txt, 1));
		*heredoc = ft_strjoin(*heredoc, txt);
		if (!(*heredoc))
			return (0);
		free(txt);
		txt = ft_strdup("");
		if (!txt)
			return (free_txt_ndeal(new_deal, txt, 2));
	}
	return (2);
}
