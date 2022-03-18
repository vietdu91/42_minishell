/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_to_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:02:36 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/18 19:50:19 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin_2(t_args *args)
{
	if (!ft_strcmp(args->parser->head->content_exp_sans_q, "env"))
	{
		display_env(args->parser->head, args->env);
		return (0);	
	}
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "pwd"))
	{
		pwd_main(args->parser->head, args);
		return (0);	
	}
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "unset"))
	{
		unset_main(args, args->parser->head);
		return (0);
	}
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "scare_me"))
	{
		print_scare_me();
		return (0);
	}
	else if (!ft_strcmp(args->parser->head->content_exp_sans_q, \
	"patience_is_a_virtue"))
	{
		print_patience(args);
		return (0);	
	}
	return (-1);
}

int	is_builtin_1(t_args *args)
{
	args->nb_commands = how_many_commands(args->buffer);
	if (args->parser->head)
	{
		if (!ft_strcmp(args->parser->head->content_exp_sans_q, "cd"))
		{
			cd_main(args, args->env, args->parser->head);
			return (0);
		}
		else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "export"))
		{
			export_main(args, args->env, args->export, args->parser->head);
			return (0);
		}
		else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "exit"))
		{
			exit_main(args, args->parser->head);
			return (0);
		}
		else if (!ft_strcmp(args->parser->head->content_exp_sans_q, "echo"))
		{
			echo_main(args, args->parser->head);
			return (0);	
		}
	}
	return (is_builtin_2(args));
}
