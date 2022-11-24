/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 22:19:28 by emtran            #+#    #+#             */
/*   Updated: 2022/05/02 12:21:24 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	type_meta(int type)
{
	if (type == 6 || type == 7 || type == 8 || type == 11 \
	|| type == 13 || type == 15 || type == 17 || type == 19)
		return (1);
	return (0);
}

int	is_pipe_or_wrong(int type)
{
	const int	meta[] = {6, 20};
	int			i;

	i = -1;
	while (++i < 2)
		if (meta[i] == type)
			return (1);
	return (0);
}
