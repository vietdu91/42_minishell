/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 20:33:20 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/04 21:13:27 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

void	loop(t_args *args)
{
	while (1)
	{
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
				lexer_maestro(args);
				exec_maestro(args);
				// display_parsing(args->parser);
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
	// int	i;

	// i = 0;
	args->nb_commands = how_many_commands(args->buffer);
	if (!ft_strcmp(args->buffer, "export"))
		display_export(args->export);
	if (!ft_strcmp(args->buffer, "cd"))
		cd_main(args->home, args);
	if (args->parser->head)
	{
		if (!ft_strcmp(args->parser->head->content_exp_sans_q, "exit"))
			exit_main(args, args->parser->head);
		if (!ft_strcmp(args->parser->head->content_exp_sans_q, "echo"))
			echo_main(args, args->parser->head);
		if (!ft_strcmp(args->parser->head->content_exp_sans_q, "env"))
			display_env(args->parser->head, args->env);
		if (!ft_strcmp(args->parser->head->content_exp_sans_q, "pwd"))
			pwd_main(args->parser->head, args);
		if (!ft_strcmp(args->parser->head->content_exp_sans_q, "unset"))
			unset_main(args, args->parser->head);
		if (!ft_strcmp(args->parser->head->content_exp_sans_q, "scare_me"))
			print_scare_me();
		if (!ft_strcmp(args->parser->head->content_exp_sans_q, \
		"patience_is_a_vertue"))
			print_patience(args);
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
