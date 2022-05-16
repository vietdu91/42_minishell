/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter_for_pipex_norm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:09:56 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 16:13:31 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	return_delimiter_to_tab(char **delimiters, int i)
{
	if (!delimiters[i])
	{
		malloc_failed(delimiters, i);
		return (1);
	}
	return (0);
}
