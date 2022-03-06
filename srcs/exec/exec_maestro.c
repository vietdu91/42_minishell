/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_maestro.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 17:58:40 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/03 00:54:17 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// int	no_heredoc(t_struct *c, int argc, char **argv)
// {
// 	int			i;

// 	i = 1;
// 	while (++i < argc - 1)
// 	{
// 		if (cmd_is_path(argv[i], c))
// 		{
// 			if (!list_end(c->l_pathes, c->av[i]))
// 				return (0);
// 			free(c->final_path);
// 		}
// 		else
// 		{
// 			if (!get_f_path(c, argv[i]))
// 			{
// 				perror("Not a command\n");
// 				return (0);
// 			}			
// 		}
// 	}
// 	return (1);
// }

int	read_heredoc(char *heredoc, char *del)
{
	char		buf[2];
	char		*txt;

	heredoc = ft_strdup("");
	txt = ft_strdup("");
	if (!txt || !heredoc)
		return (0);
	while (read(0, buf, 1) > 0)
	{
		buf[1] = 0;
		txt = ft_strjoin(txt, buf);
		if (strchr(txt, '\n'))
		{
			if (ft_strncmp(txt, del, ft_strlen(txt) - 1) == 0)
			{
				free(txt);
				return (1);
			}
			heredoc = ft_strjoin(heredoc, txt);
			if (!heredoc)
				return (0);
			free(txt);
			txt = ft_strdup("");
			if (!txt)
				return (0);
		}
	}
	free(txt);
	return (0);
}

// int	heredoc_parser(t_struct *c)
// {
// 	int			i;

// 	i = 2;
// 	while (++i < c->ac - 1)
// 	{
// 		if (cmd_is_path(c->av[i], c))
// 		{
// 			if (!list_end(c->l_pathes, c->av[i]))
// 			{
// 				free_end(c);
// 				return (0);
// 			}
// 		}
// 		else
// 		{
// 			if (!get_f_path(c, c->av[i]))
// 			{
// 				perror("not a command");
// 				return (0);
// 			}
// 		}
// 	}
// 	return (1);
// }

// int	choose_parser(t_struct *c, int argc, char **argv)
// {
// 	if (c->heredoc == 1)
// 		return (heredoc_here(c));
// 	else
// 		return (no_heredoc(c, argc, argv));
// }

int exec_maestro(t_args *args)
{
	t_exec	exec;

	exec.env = init_env_tab(args->env);
	exec.hdocs = count_heredoc(args->parser);
	exec.delimiters = delimiters_to_tab(args->parser, exec.hdocs);
	fill_d_tab_heredoc(&exec, exec.hdocs, exec.delimiters);
	return (0);
}
