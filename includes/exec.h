/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 09:25:05 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/17 21:02:53 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

typedef struct s_cmds
{
	struct t_cmds	*next;
	char			*path;
	int				is_path;
	char			**tab_cmd;
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
}	t_exec;

/*				CMD_IS_PATH.C			*/
void			ft_close(int fd, char *str);
char			*cut_path(char *str, char *no_space);
int				cmd_is_path(char *array, t_pars_node *c);

/* 				CONVERTER_FOR_PIPEX.C	*/

void			str_to_content(char *str, char *content, int *i, int *j);
char			*remove_quotes(char *str, char *content);
char			*remove_quotes_delimiters(char *str);
char			**delimiters_to_tab(t_pars_list *l, int size, t_args *args);
char			**content_to_d_tab(int iter, int *index, t_pars_node *cpy);

/*				CONVERTER_FOR_PIPEX_NORM.C			*/
int				return_delimiter_to_tab(char **delimiters, int i);

/*              DATA_EXEC.C             */
int				boucle_heredoc(char buf[2], char **txt, char *new_deal, \
				char **heredoc);
int				dup_et_close(int datas[5]);
void			signal_et_delete(t_args *args);
void			dernier_truc(int datas[5], t_pars_node *i, t_pars_list *l, \
t_args *args);

// int				join_heredoc(char **heredoc, char *txt, char *del);
int				free_txt_ndeal(char *new_deal, char *txt, int n);
int				read_heredoc(char **heredoc, char *del);
int				size_d_tab(t_pars_list *l);
void			check_cmds(t_pars_list *l);
int				exec_maestro(t_args *args);

/*				DUP_AND_CLOSE.C			*/

int				close_maestro(int datas[5], t_pars_list *l);
int				datas_zero(int datas[5], t_pars_list *l, t_pars_node *cpy);
int				dup_maestro(int datas[5], t_pars_list *l, t_pars_node *cpy);

/*				DUP_AND_CLOSE_NORM.C	*/
int				datas_middle_part_2(t_pars_node *cpy, \
				int datas[5], t_pars_list *l);
int				datas_zero_part2(t_pars_node *cpy, int datas[5], \
				t_pars_list *l);

/*				EXEC_MAP_UTILS.C		*/

int				find_in(t_pars_list *l);
int				find_out(t_pars_list *l);
void			delete_content_useless_infiles(t_pars_list *l);
int				size_2dtab(char **dtab);
void			create_infiles_outfiles(t_args *args, int in_out[2], \
				t_pars_node *cpy, char **fds_content);

/*				EXECUTION.C			*/
int				reset_in_out(int datas[5], t_pars_list *l, int n);
int				count_cmd(t_pars_list *l);
int				pid_zero_execution(t_pars_node *cpy, \
				t_args *args, int data, int datas[5]);
int				fork_execution(int datas[5], t_pars_node *i, t_pars_list *l, \
				t_args *args);
int				loop_execution(t_args *args, t_pars_list *l);

/*				EXECUTION_NORM.C				*/
void			dup_pid(t_pars_node *i, t_args *args, int datas[5], int n);

/*				EXPAND_HEREDOC.C				*/

int				quotes_or_not(char *str);
char			*send_variable(char *line, t_env_list *env);
char			*split_to_join(char **d_tab);
int				modify_heredoc(char **hdoc, char *limitator, t_env_list *env);

/*				EXPAND_HEREDOC_NORM.C			*/
char			*size_and_malloc(char **d_tab);

/*				HEREDOC.C						*/

int				count_heredoc(t_pars_list *l);
int				fill_d_tab_heredoc(t_args *args, int size, char **eof);

/*				INF_OUT.C						*/

char			**create_fd_tab(t_pars_node *inf, t_pars_node *out);
int				file_create_loop(t_pars_list *l);
char			**fill_fds(t_pars_node *cpy);
int				inf_out_maestro(t_args *args, t_pars_list *l);

/*				LEAKS_EXEC.C				*/

int				malloc_failed(char **env, int size);

/*				OPTIONS_EXEC.C				*/

int				count_cmds(t_pars_list *l);
int				count_options(t_pars_node *cpy);
int				*create_and_fill_options(t_pars_list *l, int size);
char			**create_options_tab(t_pars_node *cpy, int limit);
int				options_maestro(t_args *args, t_pars_list *l);

/*				PATH_MANAGER.C				*/

char			**check_errors(char *array, char *cmd);
char			*return_path(char **to_try);
void			if_no_cmd_is_path(char *path, char **to_try, t_pars_node *node);
int				path_maestro(t_args *args);

/*				ROAD_TO_BUILTINS.C			*/

int				is_builtin(t_pars_node *node);
int				which_node(t_pars_list *l, int n);
int				return_or_exit(int n, t_args *args, int dats[5]);
int				exec_builtin_1(t_args *args, t_pars_node *node, \
				int n, int datas[5]);
int				exec_builtin_2(t_args *args, t_pars_node *node, \
				int n, int datas[5]);
int				exec_builtin_3(t_args *args, t_pars_node *node, \
				int n, int datas[5]);
int				which_builtin(t_args *args, t_pars_list *l, int n);

/*				UTILS_PATH.C				*/

void			add_slash(char **to_try);
int				add_cmd(char **to_try, char *cmd);

#endif