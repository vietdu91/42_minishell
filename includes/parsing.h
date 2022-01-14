/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:10 by emtran            #+#    #+#             */
/*   Updated: 2022/01/14 18:00:39 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include "./bultin.h"

/*typedef struct s_exit_status
{
	int	interrogation;
}	t_exit_status;*/

typedef struct s_operator
{
	int		pipe;
	int		double_pipe;
	int		double_appersand;
}	t_operator;

typedef struct s_redir
{
	int		to_output;
	int		to_input;
	int		append_output;
	int		heredoc;
}	t_redir;

typedef struct s_builtin
{
	char		**tab_builtin;
	t_cd		*cd;
	t_echo		*echo;
	t_env		*env;
	t_export	*export;
	t_history	*history;
	t_pwd		*pwd;
	t_unset		*unset;
}	t_builtin;

/* pointeurs sur les structs de type fichier builtin etc */
typedef struct s_args
{
	t_builtin		*builtin;
	t_redir			*redir;
	t_operator		*operator;
	char			*buffer;
	char			**env;
	char			*path;
	char			*pwd;
	char			*oldpwd;
}	t_args;
/* checker comment faire differents types de struct*/

/* maillons de la liste chainee */

typedef struct s_node
{
	struct s_node	*next;
	char			*content;
	char			*option;
	int				index;
	char			**cmd;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail; // il sert a quoi ?
	int		length;
}	t_list;

/*		FIND_IN_ENV.C		*/

char	*find_path(char **envp);
char	*find_pwd(char **envp);
char	*find_oldpwd(char **envp);

#endif
