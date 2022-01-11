/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coucou.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:56:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/11 14:20:55 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

int	main(void)
{
	char	*buffer;

	while (1)
	{
		buffer = readline(PROMPT);
		if (buffer == NULL)
		{
			ft_putstr("exit\n", 1);
		}
		if (ft_strcmp(buffer, "scare_me"))
		{
			printf(" .-.\n");
			printf("(o o) boo!\n");
			printf("| O \\\n");
			printf(" \\   \\\n");
			printf("  `~~~'\n");
		}
		if (ft_strcmp(buffer, "exit"))
		{
			printf("exit \n");
			exit(EXIT_SUCCESS);
		}
		printf("cmd = %s\n", buffer);
	}
}
