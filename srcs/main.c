/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:33:20 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 14:07:58 by emtran           ###   ########.fr       */
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
	j = 0;
	size = 0;
	while (buffer[++i])
		if (buffer[i] > 0)
			size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (buffer[++i])
		if (buffer[i] > 0)
			str[j++] = buffer[i];
	str[j] = 0;
	free(buffer);
	return (str);
}

void	loop(t_args *args)
{
	while (1)
	{
		all_ignore();
		init_parsing_list(&args->parser);
		args->buffer = readline(PROMPT);
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
				if (!lexer_maestro(args))
					exec_maestro(args);
			}
			add_history(args->buffer);
		}
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
	loop(args);
	free_all(args);
	return (0);
}
