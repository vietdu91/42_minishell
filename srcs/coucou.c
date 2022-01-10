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

int	main()
{
	char	*buffer = NULL;
	size_t	buf_size = 2048;

	buffer = (char *)ft_strcalloc(sizeof(char), buf_size);
	if (buffer == NULL) 
	{
		perror("Hoho il y a un problème de malloc...");
		return (EXIT_FAILURE);
	}
	ft_putstr("minishell of the hell $> ", 1);
	while (getline(&buffer, &buf_size, stdin) > 0) 
	{
		printf("cmd = %s\n", buffer);
		ft_putstr("minishell of the hell $> ", 1);
	}
	printf("Casse-toi pov' con \n");
	free(buffer);
}
