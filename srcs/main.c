/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:33:20 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/25 14:24:02 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

char	*buffer_cleaner(char *buffer)
{
	char	*str;
	int		i;
	int		size;
	int		j;

	i = -1;
	size = 0;
	while (buffer[++i])
		if (buffer[i] > 0)
			size++;
	str = malloc (sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (buffer[++i])
		if (buffer[i] > 0)
			str[j++] = buffer[i];
	str[j] = 0;
	return (str);
}

void	loop(t_args *args)
{
	while (1)
	{
		init_parsing_list(&args->parser);
		args->buffer = readline(PROMPT);
		args->buffer = buffer_cleaner(args->buffer);
		// printf("main args->buffer = %s\n", args->buffer);
		if (!args->buffer)
		{
			ft_putstr("exit\n", 1);
			break ;
		}
		else
		{
			if (!check_unclosed(args))
			{
				parsing_maestro(args, args->buffer);
				lexer_maestro(args);
				// display_parsing(args->parser);
				exec_maestro(args);
				// display_parsing(args->parser);
			}
			add_history(args->buffer);
		}
		//free_all(args);
		if (args->parser)
			free_pars_list(args->parser);
		free(args->buffer);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	(void) argc;
	(void) argv;
	print_demon();
	args = NULL;
	args = malloc(sizeof(t_args));
	if (!args)
		intersection_of_errors(2, args);
	init_and_set_all(args, envp);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &signal_ctlr_c);
	loop(args);
	free_all(args);
	return (0);
}
