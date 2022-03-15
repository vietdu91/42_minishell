/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 18:15:04 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/15 15:02:40 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int fill_fds(t_pars_list *l)
{
    t_pars_node *node;

    node = l->head;
	(void)node;
	return (1);
}

int     inf_out_maestro(t_args *args, t_pars_list *l)
{
    fill_fds(l);
	(void)args;
	return (1);
}
