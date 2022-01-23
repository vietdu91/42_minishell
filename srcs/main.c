/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:56:08 by emtran            #+#    #+#             */
/*   Updated: 2022/01/23 15:56:12 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_status;

void	loop(char **envp, t_args *args)
{
	while (1)
	{
		args->buffer = readline(PROMPT);
		add_history(args->buffer);
		if (!args->buffer)
		{
			ft_putstr("exit\n", 1);
			break ;
		}
		else
			cmp_all(args, envp);
		free(args->buffer);
	}
}

void	cmp_all(t_args *args, char **envp)
{
	int	i;

	i = 0;
	if (check_unclosed(args) == 1)
		return ;
	(void) envp;
	args->nb_commands = how_many_commands(args->buffer);
	if (ft_strcmp(args->buffer, "env"))
		display_env(args);
	if (ft_strcmp(args->buffer, "cd"))
		cd_main(args->home);
	if (ft_strcmp(args->buffer, "pwd"))
		pwd_main();
	if (ft_strcmp(args->buffer, "scare_me"))
		print_scare_me();
	if (ft_strcmp(args->buffer, "exit"))
		exit_main(args);
	if (ft_strcmp(args->buffer, "echo $?"))
		printf("%d\n", g_exit_status);
/*	maestro(args->buffer);
	printf("cmd = %s\n", args->buffer);
	printf("PATH = %s\n", args->path);
	printf("PWD = %s\n", args->pwd);
	printf("OLDPWD = %s\n", args->oldpwd);*/
}

int	main(int argc, char **argv, char **envp)
{
	t_args	*args;

	(void) argc;
	(void) argv;
	args = NULL;
	args = malloc(sizeof(t_args));
	if (!args)
		fork_of_errors(2, args);
	if (!envp)
		fork_of_errors(1, args);
	init_and_set_all(args, envp);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, &signal_ctlr_c);
	loop(envp, args);
	free_all(args);
	return (0);
}
