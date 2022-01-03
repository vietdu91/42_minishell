/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coucou.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:56:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/03 14:40:17 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char	*str;
	int		a;

	a = -1;
	str = "205615dfdggdSFGZFz53656fd1";
	while (str[++a])
	{
		if (is_alphanumeric(str[a]) == 0)
		{
			printf("MAIS NON");
			return (0);
		}
	}
	printf("MAIS OUI");
	return (0);
}
