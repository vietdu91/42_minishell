/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coucou.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:56:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/10 14:26:21 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char	*str;
	int		a;

	a = -1;
	str = "   )  (      )          ";
//	while (str[++a])
//	{
	if (is_unclosed_parenth(str) != 0)
	{
		printf("MAIS NON");
		return (0);
	}
//	}
	printf("MAIS OUI");
	return (0);
}
