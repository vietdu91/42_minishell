/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:56:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/31 14:20:49 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

void	loop(t_args *args)
{
	while (1)
	{
		args->buffer = readline(PROMPT);
		maestro(args, args->buffer);
		add_history(args->buffer);
		if (!args->buffer)
		{
			ft_putstr("exit\n", 1);
			break ;
		}
		else
			cmp_all(args);
		free(args->buffer);
	}
}

void	cmp_all(t_args *args)
{
	int	i;

	i = 0;
	if (check_unclosed(args))
		return ;
	args->nb_commands = how_many_commands(args->buffer);
	if (!ft_strcmp(args->buffer, "echo"))
		ft_putchar('\n', 1);
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
	if (!ft_strcmp(args->buffer, "exit"))
		exit_main(args);
	if (!ft_strcmp(args->buffer, "echo $?"))
		printf("%d\n", g_exit_status);
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
