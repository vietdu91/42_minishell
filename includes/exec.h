/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:25:05 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/02 18:39:41 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "./minishell.h"

typedef struct s_exec
{
	int     hdocs;
	char    **heredocs;
	char    **delimiters;
	char    **env;
}   t_exec;


/*      COVERTER_FOR_PIPEX.C	*/
char	**init_env_tab(t_env_list *l);
char	**init_parse_to_tab(t_pars_list *l);
char 	**delimiters_to_tab(t_pars_list *l, int size);

/*		EXEC_MAESTRO.C			*/
char	**init_env_tab(t_env_list *l);
int		exec_maestro(t_args *args);

/*		HEREDOCS.C				*/
int		read_heredoc(char *heredoc, char *del);
int		count_heredoc(t_pars_list *l);
int		fill_d_tab_heredoc(t_exec *args_exec, int size, char **eof);

/*		LEAKS_EXEC.C			*/
int 	malloc_failed(char **env, int size);
#endif