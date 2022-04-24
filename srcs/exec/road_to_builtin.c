/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road_to_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 23:02:36 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/24 19:11:53 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(t_pars_node *node)
{
	if (!ft_strcmp(node->content_exp_sans_q, "env"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "pwd"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "unset"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "scare_me"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, \
	"patience_is_a_virtue"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "cd"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "export"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "exit"))
		return (0);
	else if (!ft_strcmp(node->content_exp_sans_q, "echo"))
		return (0);
	// printf("%s n'est pas un builtin\n", node->content);
	return (1);
}

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
			{	
				return (is_builtin(node));
			}
		}
		node = node->next;
	}
	return (0);
}

int	return_or_exit(int n)
{
	if (n == 1)
	{
		// printf("salida n = %d\n", n);
		return (0);
	}
	else
	{
		// ft_putstr("je suis le traitre\n", 1);
		exit(0);
	}
	return (0);
}

int	exec_builtin_3(t_args *args, t_pars_node *node, int n)
{
	if (!ft_strcmp(node->content_exp_sans_q, "scare_me"))
	{
		print_scare_me();
		return (return_or_exit(n));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, \
	"patience_is_a_virtue"))
	{
		print_patience(args);
		return (return_or_exit(n));
	}
	return (-1);
}

int	exec_builtin_2(t_args *args, t_pars_node *node, int n)
{
	if (!ft_strcmp(node->content_exp_sans_q, "env"))
	{
		// printf("ENV SE LANCE\n");
		display_env(node, args->env);
		return (return_or_exit(n));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, "pwd"))
	{
		// printf("n ======= %d\n", n);
		pwd_main(node, args);
		return (return_or_exit(n));
	}
	else if (!ft_strcmp(node->content_exp_sans_q, "unset"))
	{
		unset_main(args, node);
		return (return_or_exit(n));
	}
	return (exec_builtin_3(args, node, n));
}

int	exec_builtin_1(t_args *args, t_pars_node *node, int n)
{
	if (node)
	{
		if (!ft_strcmp(node->content_exp_sans_q, "cd"))
		{
			cd_main(args, args->env, node);
			return (return_or_exit(n));
		}
		else if (!ft_strcmp(node->content_exp_sans_q, "export"))
		{
			export_main(args, args->env, args->export, node);
			return (return_or_exit(n));
		}
		else if (!ft_strcmp(node->content_exp_sans_q, "exit"))
		{
			exit_main(args, node);
			return (return_or_exit(n));
		}
		else if (!ft_strcmp(node->content_exp_sans_q, "echo"))
		{
			echo_main(args, node);
			return (return_or_exit(n));
		}
	}
	// printf("on entre dans le exec builtin\n");
	return (exec_builtin_2(args, node,  n));
}

// int	which_builtin(t_args *args, t_pars_node *node, int n)
// {
// 	t_pars_node	*node;
// 	int			i;

// 	i = 0;
// 	node = l->head;
// 	while (node)
// 	{
// 		if (node->type == CMD)
// 		{
// 			printf("KONTENT = %s\n", node->content);
// 			if (i == n)
// 				return (exec_builtin_1(args, node, n));
// 			i++;
// 		}
// 		node = node->next;
// 	}
// 	return (0);
// }