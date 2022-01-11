/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:56:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/11 18:27:00 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_data	g_data;

void	loop(void)
{
	char	*buffer;

	g_data.exit_status = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &signal_ctlr_c);
	while (1)
	{
		buffer = readline(PROMPT);
		if (buffer == NULL)
		{
			ft_putstr("exit\n", 1);
		}
		if (!buffer)
		{
			break ;
		}
		else
		{
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
			if (ft_strcmp(buffer, "echo $?"))
			{
				printf("%d\n", g_data.exit_status);
			}
			printf("cmd = %s\n", buffer);
		}
	}
}

int	main(void)
{
	loop();
	return (0);
}
