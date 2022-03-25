/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:10:01 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 14:56:57 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	error_numeric_exit(t_args *args,char *content)
{
	ft_putstr("bash: exit: ", 2);
	ft_putstr(content, 2);
	ft_putstr(": numeric argument required\n", 2);
	g_exit_status = 2;
	free_all(args);
	exit(g_exit_status);
}

int	check_len_llu_nb(char *content)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (content[i] == '+' || content[i] == '-')
		i++;
	while (content[i])
	{
		len++;
		i++;
	}
	if (len > 19)
		return (1);
	return (0);
}

void	say_hello_wave_goodbye(t_args *args,char *content, int neg, \
unsigned long long exit_status)
{
	long long	new_exit_status;

	new_exit_status = 0;
	if (content[0] == '-')
		neg = 1;
	if (check_len_llu_nb(content))
		error_numeric_exit(args, content);
	exit_status = ft_atoull(content);
	if ((exit_status > LLONG_MAX && neg == 0) || \
	(exit_status > 9223372036854775808uLL && neg == 1))
		error_numeric_exit(args, content);
	else
	{
		if (neg == 1)
		{
			new_exit_status = (long long)exit_status * -1;
			g_exit_status = new_exit_status % 256;
		}
		else
			g_exit_status = exit_status % 256;
	}
	free_all(args);
	exit(g_exit_status);
}

void	exit_main(t_args *args, t_pars_node *parser)
{
	unsigned long long	exit_status;
	t_pars_node			*node;
	int					neg;

	neg = 0;
	exit_status = 0;
	node = parser->next;
	ft_putstr("exit\n", 1);
	if (node)
	{
		if (check_only_digits(node->content_exp_sans_q))
			error_numeric_exit(args, node->content_exp_sans_q);
		else if (node->next)
		{
			print_error(BASH, CMD_EXIT, NULL, ERR_MANY_ARG);
			g_exit_status = 1;
			return ;
		}
		else
			say_hello_wave_goodbye(args, node->content_exp_sans_q, neg, \
			exit_status);
	}
	free_all(args);
	exit(EXIT_SUCCESS);
}
