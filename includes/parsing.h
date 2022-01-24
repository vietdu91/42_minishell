/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:10 by emtran            #+#    #+#             */
/*   Updated: 2022/01/24 14:16:32 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*typedef struct s_exit_status
{
	int	interrogation;
}	t_exit_status;*/

typedef struct s_pwd
{
	int	pwd_on;
}	t_pwd;

typedef struct s_history
{
	int	history_on;
}	t_history;

typedef struct s_exit
{
	int		exit_on;
	int		nb;
}	t_exit;

typedef struct s_export
{
	int		export_on;
}	t_export;

typedef struct s_unset
{
	int		unset_on;
}	t_unset;

typedef struct s_cd
{
	int		cd_on;
}	t_cd;

typedef struct s_echo
{
	int		echo_on;
	int		option_n;
}	t_echo;

typedef struct s_builtin
{
	char		**tab_builtin;
	t_cd		*cd;
	t_echo		*echo;
	t_export	*export;
	t_history	*history;
	t_pwd		*pwd;
	t_unset		*unset;
}	t_builtin;

enum	e_type
{
	EMPTY,
	SIMPLE_ARG,
/*		<		*/
	INPUT,
	INFILE,
/*		>		*/
	OUTPUT,
	OUTFILE,
/*		>>		*/
	SUPER_OUTPUT,
	SUPER_OUTFILE,
/*		<<		*/
	HEREDOC,
	LIMITATOR,
};

enum	e_var
{
	BASIC,
	PWD,
	OLDPWD,
	HOME,
	SHLVL,
};
/* maillons de la liste chainee */

typedef struct s_node
{
	struct s_node	*next;
	char			*content;
	enum e_type		type;
	int				quote_or_not; 
//	0_nothing ; 1_simple_quote ; 2_double_quote
	int				index;
	char			**cmd;
}	t_node;

typedef struct s_env
{
	char			*line;
	char			*variable;
	char			*content;
	enum e_var		var_id;
	struct s_env	*next;
}	t_env;

typedef struct s_env_list
{
	t_env	*head;
	t_env	*tail;
	int		length;
}	t_env_list;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		length;
}	t_list;

typedef struct s_args
{
	t_builtin		*builtin;
	t_env_list		*env;
	char			*buffer;
	char			*path;
	char			*pwd;
	char			*oldpwd;
	char			*home;
	int				nb_commands;
}	t_args;



/*		FIND_IN_ENV.C		*/

char	*find_path(char **envp);
char	*find_pwd(char **envp);
char	*find_oldpwd(char **envp);
char	*find_home(char **envp);

/*		PARSER.C			*/

void	zap_spaces(char **line);
char	*first_word(char **str);
int		parser(char **line);
int		maestro(char *line);
#endif
