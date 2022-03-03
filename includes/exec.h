/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:25:05 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/03 16:41:50 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "./minishell.h"

typedef struct s_cmds
{
	struct	t_cmds	*next;
	char	*path;
	int		is_path;
	char	**tab_cmd;
}	t_cmds;

typedef struct s_cmds_list
{
	t_cmds	*head;
	t_cmds	*tail;
	int		length;
}	t_cmds_list;

typedef struct s_exec
{
	int					hdocs;
	char				**heredocs;
	char				**delimiters;
	char				**env;
	t_args				*args;
	// t_cmds				*cmds;
}	t_exec;


/* 		COVERTER_FOR_PIPEX.C	*/
char			**init_env_tab(t_env_list *l);
char			**init_parse_to_tab(t_pars_list *l);
char			**delimiters_to_tab(t_pars_list *l, int size);

/*		EXEC_MAESTRO.C			*/
char			**init_env_tab(t_env_list *l);
int				exec_maestro(t_args *args);

/*		HEREDOCS.C				*/
int				read_heredoc(char *heredoc, char *del);
int				count_heredoc(t_pars_list *l);
int				fill_d_tab_heredoc(t_exec *args_exec, int size, char **eof);

/*		INIT_CMDS				*/
t_cmds_list		*init_list(void);

/*		LEAKS_EXEC.C			*/
int				malloc_failed(char **env, int size);
#endif