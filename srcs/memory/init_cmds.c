/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:13:19 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 18:46:59 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_cmds_list	*init_list(void)
{
	t_cmds_list	*list;

	list = NULL;
	list = (t_cmds_list *)malloc(sizeof(t_cmds_list));
	if (!list)
		return (NULL);
	ft_memset(&list, 0, sizeof(list));
	return (list);
}
