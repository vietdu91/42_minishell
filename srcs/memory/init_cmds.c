/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 01:13:19 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/21 15:19:24 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

	// list->head = NULL;
	// list->tail = NULL;
	// list->length = 0;

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
