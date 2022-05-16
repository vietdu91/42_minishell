/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_to_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:02:36 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/16 17:47:01 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	which_node(t_pars_list *l, int n)
{
	t_pars_node	*node;
	int			i;

	i = 0;
	node = l->head;
	while (node)
	{
		if (node->type == CMD)
		{
			i++;
			if (i == n)
				return (is_builtin(node));
		}
		node = node->next;
	}
	return (0);
}

int	return_or_exit(int n, t_args *args, int datas[5])
{
	if (datas[2] > 0)
		ft_close(datas[2], args->parser->pid);
	if (datas[1] > 1)
	{
		ft_close(0, args->parser->pid);
		ft_close(1, args->parser->pid);
		ft_close(datas[3], args->parser->pid);
	}
	ft_close(datas[4], args->parser->pid);
	if (args->parser->pipe[0])
		ft_close(args->parser->pipe[0], args->parser->pid);
	if (args->parser->pipe[1])
		ft_close(args->parser->pipe[1], args->parser->pid);
	reset_in_out(datas, args->parser, 1);
	if (n == 1)
		return (0);
	else
	{
		free_all(args);
		exit(0);
	}
	return (0);
}

int	exec_builtin_3(t_args *args, t_pars_node *node, int n, int datas[5])
{
	if (!ft_strcmp(node->content_exp_sans_q, "scare_me"))
	{
		print_scare_me();
		return (return_or_exit(n, args, datas));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, \
	"patience_is_a_virtue"))
	{
		print_patience(args);
		return (return_or_exit(n, args, datas));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, "echo"))
	{
		echo_main(args, node);
		return (return_or_exit(n, args, datas));
	}
	return (-1);
}

int	exec_builtin_2(t_args *args, t_pars_node *node, int n, int datas[5])
{
	if (!ft_strcmp(node->content_exp_sans_q, "env"))
	{
		display_env(node, args->env);
		return (return_or_exit(n, args, datas));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, "pwd"))
	{
		pwd_main(node, args);
		return (return_or_exit(n, args, datas));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, "unset"))
	{
		unset_main(args, node);
		return (return_or_exit(n, args, datas));
	}
	return (exec_builtin_3(args, node, n, datas));
}

int	exec_builtin_1(t_args *args, t_pars_node *node, int n, int datas[5])
{
	if (node)
	{
		if (!ft_strcmp(node->content_exp_sans_q, "cd"))
		{
			cd_main(args, args->env, node);
			return (return_or_exit(n, args, datas));
		}
		else if (!ft_strcmp(node->content_exp_sans_q, "export"))
		{
			export_main(args, node, args->export);
			return (return_or_exit(n, args, datas));
		}
		else if (!ft_strcmp(node->content_exp_sans_q, "exit"))
		{
			exit_main(args, node);
			return (return_or_exit(n, args, datas));
		}
	}
	return (exec_builtin_2(args, node, n, datas));
}
