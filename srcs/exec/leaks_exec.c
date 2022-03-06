/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leaks_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:19:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/02 19:04:38 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int malloc_failed(char **env, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(env[i]);
	env = NULL;
	return (0);
}
