/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_to_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:02:36 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/21 12:26:40 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_args *args)
{
	if (!ft_strcmp(args->parser->head->content_exp_sans_q, "env"))
		return (0);
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "pwd"))
		return (0);
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "unset"))
		return (0);
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "scare_me"))
		return (0);
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, \
	"patience_is_a_virtue"))
		return (0);
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "cd"))
		return (0);
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "export"))
		return (0);
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "exit"))
		return (0);
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "echo"))
		return (0);
	return (1);
}

int	return_or_exit(int n)
{
	if (n == 1)
		return (0);
	else
		exit(0);
	return (0);
}

int	exec_builtin_3(t_args *args, int n)
{
	if (!ft_strcmp(args->parser->head->content_exp_sans_q, "scare_me"))
	{
		print_scare_me();
		return (return_or_exit(n));
	}
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, \
	"patience_is_a_virtue"))
	{
		print_patience(args);
		return (return_or_exit(n));
	}
	return (-1);
}

int	exec_builtin_2(t_args *args, int n)
{
	if (!ft_strcmp(args->parser->head->content_exp_sans_q, "env"))
	{
		display_env(args->parser->head, args->env);
		return (return_or_exit(n));
	}
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "pwd"))
	{
		pwd_main(args->parser->head, args);
		return (return_or_exit(n));
	}
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "unset"))
	{
		unset_main(args, args->parser->head);
		return (return_or_exit(n));
	}
	return (exec_builtin_3(args, n));
}

int	exec_builtin_1(t_args *args, int n)
{
	if (args->parser->head)
	{
		if (!ft_strcmp(args->parser->head->content_exp_sans_q, "cd"))
		{
			cd_main(args, args->env, args->parser->head);
			return (return_or_exit(n));
		}
		else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "export"))
		{
			export_main(args, args->env, args->export, args->parser->head);
			return (return_or_exit(n));
		}
		else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "exit"))
		{
			exit_main(args, args->parser->head);
			return (return_or_exit(n));
		}
		else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "echo"))
		{
			echo_main(args, args->parser->head);
			return (return_or_exit(n));
		}
	}
	return (exec_builtin_2(args, n));
}
