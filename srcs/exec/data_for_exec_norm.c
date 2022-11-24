/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_for_exec_norm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:34:12 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/17 21:02:28 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	boucle_heredoc(char *buf, char **txt, char *new_deal, char **heredoc)
{
	buf[1] = 0;
	*txt = ft_strjoin(*txt, buf);
	if (ft_strchr(*txt, '\n'))
	{
		if (!ft_strcmp(*txt, new_deal))
			return (free_txt_ndeal(new_deal, *txt, 1));
		*heredoc = ft_strjoin(*heredoc, *txt);
		if (!(*heredoc))
			return (0);
		free(*txt);
		*txt = ft_strdup("");
		if (!*txt)
			return (free_txt_ndeal(new_deal, *txt, 2));
	}
	return (2);
}

int	dup_et_close(int datas[5])
{
	dup2(datas[3], STDIN_FILENO);
	dup2(datas[4], STDOUT_FILENO);
	close(datas[3]);
	close(datas[4]);
	return (0);
}

void	signal_et_delete(t_args *args)
{
	signal(SIGINT, &signal_ignore);
	signal(SIGQUIT, &signal_ignore);
	delete_content_useless_infiles(args->parser);
}

void	dernier_truc(int datas[5], t_pars_node *i, t_pars_list *l, \
t_args *args)
{
	if ((is_builtin(i) || is_builtin(i) == -10 || \
	(!is_builtin(i) && datas[1] > 1)))
		fork_execution(datas, i, l, args);
	else
		dup_pid(i, args, datas, 0);
	if (datas[1] == 1 && !is_builtin(i))
		dup_et_close(datas);
}

void	print_fd(int datas[5], t_pars_list *l)
{
	return ;
	ft_putstr("datas[2] == ", 2);
	ft_putnbr(datas[2], 2);
	ft_putstr("\n", 2);
	ft_putstr("datas[3] == ", 2);
	ft_putnbr(datas[3], 2);
	ft_putstr("\n", 2);
	ft_putstr("datas[4] == ", 2);
	ft_putnbr(datas[4], 2);
	ft_putstr("\n", 2);
	ft_putstr("pipe[0] == ", 2);
	ft_putnbr(l->pipe[0], 2);
	ft_putstr("\n", 2);
	ft_putstr("pipe[1] == ", 2);
	ft_putnbr(l->pipe[1], 2);
	ft_putstr("\n", 2);
}
