/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/21 11:26:27 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	malloc_failed(char **env, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(env[i]);
	env = NULL;
	return (0);
}
