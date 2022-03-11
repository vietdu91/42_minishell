/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:25:05 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/11 01:25:17 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

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


/* 				COVERTER_FOR_PIPEX.C	*/
char			**init_env_tab(t_env_list *l);
char			**init_parse_to_tab(t_pars_list *l);
char			**delimiters_to_tab(t_pars_list *l, int size);
char			**content_to_d_tab(int iter, int *index, t_pars_node *cpy);
int				iter_tab(t_pars_list *l, int *index);

/*				CMD_IS_PATH.C			*/
char			*cut_path(char *str, char *no_space);
int				cmd_is_path(char *array, t_pars_node *c);

/*				EXEC_MAESTRO.C			*/
char			**init_env_tab(t_env_list *l);
int				exec_maestro(t_args *args);

/*				EXEC_MAP_UTILS.C		*/
void			create_infiles_outfiles(t_pars_list *l, int in_out[2], \
					int fd_tab[2], char **fds_content);

/*				EXEC_MAP.C				*/
int				simple_exec(t_args *args, t_pars_list *l);
/*				HEREDOCS.C				*/
int				read_heredoc(char *heredoc, char *del);
int				count_heredoc(t_pars_list *l);
int				fill_d_tab_heredoc(t_args *args, int size, char **eof);

/*				INIT_CMDS					*/
t_cmds_list		*init_list(void);

/*				LEAKS_EXEC.C				*/
int				malloc_failed(char **env, int size);

/*				PATH_MANAGER.C				*/
char			**check_errors(char *array, char *cmd);
char	 		*return_path(char **to_try);
int 			path_maestro(t_args *args);

/*				ROAD_TO_BUILTINS.C			*/
int 			is_builtin_1(t_args *args);

/*				UTILS_PATH.C				*/
void			add_slash(char **to_try);
int				add_cmd(char **to_try, char *cmd);
int				cmd_is_path(char *array, t_pars_node *c);
#endif