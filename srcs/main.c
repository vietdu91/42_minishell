/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:56:08 by emtran            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/02/10 14:39:29 by dyoula           ###   ########.fr       */
=======
/*   Updated: 2022/02/24 11:00:58 by emtran           ###   ########.fr       */
>>>>>>> 6d4c164ba49691b3945d26a9fa83b62092d9480c
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

unsigned long long	g_exit_status;

void	loop(t_args *args)
{
	while (1)
	{
		init_parsing_list(&args->parser);
		args->buffer = readline(PROMPT);
<<<<<<< HEAD
		if (args->buffer)
		{
			parsing_maestro(args, args->buffer);
			lexer_maestro(args);
			display_parsing(args->parser);
		}
		add_history(args->buffer);
=======
>>>>>>> 6d4c164ba49691b3945d26a9fa83b62092d9480c
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
				display_parsing(args->parser);
			}
			add_history(args->buffer);
			cmp_all(args);
		}
		if (args->parser)
			free_pars_list(args->parser);
		free(args->buffer);
	}
}

void	cmp_all(t_args *args)
{
	int	i;

	i = 0;
	args->nb_commands = how_many_commands(args->buffer);
	if (!ft_strcmp(args->buffer, "env"))
		display_env(args->env);
	if (!ft_strcmp(args->buffer, "export"))
		display_export(args->export);
	if (!ft_strcmp(args->buffer, "cd"))
		cd_main(args->home, args);
	if (!ft_strcmp(args->buffer, "pwd"))
		pwd_main(args);
	if (!ft_strcmp(args->buffer, "scare_me"))
		print_scare_me();
	if (args->parser->head)
	{
		if (!ft_strcmp(args->parser->head->content, "exit"))
			exit_main(args, args->parser->head);
		if (!ft_strcmp(args->parser->head->content, "echo"))
			echo_main(args, args->parser->head);
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
