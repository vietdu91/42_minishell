/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:10 by emtran            #+#    #+#             */
/*   Updated: 2022/01/30 20:45:14 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*typedef struct s_exit_status
{
	int	interrogation;
}	t_exit_status;*/

/*typedef struct s_pwd
{
	int		oldpwd_on;
	char	*oldpwd;
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
}	t_echo;*/

typedef struct s_parsing_node
{
	char					*content;
	int						arg;
	int						cmd;
	int						file;
	int						builtin;
	struct s_parsing_node	*previous;
	struct s_parsing_node	*next;
}	t_parsing_node;

typedef struct s_parsing_list
{
	t_parsing_node	*head;
	t_parsing_node	*tail;
	int				length;
}	t_parsing_list;

typedef struct s_builtin
{
/*	char		**tab_builtin;
	t_cd		*cd;
	t_echo		*echo;
	t_export	*export;
	t_history	*history;
	t_pwd		*pwd;
	t_unset		*unset;*/
	int		oldpwd_on;
	char	*oldpwd;
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
	t_env_list		*export;
	char			*buffer;
	char			*path;
	char			*pwd;
	char			*home;
	int				nb_commands;
}	t_args;



/*		FIND_IN_ENV.C		*/

char	*find_path(char **envp);
char	*find_pwd(char **envp);
char	*find_oldpwd(char **envp);
char	*find_home(char **envp);

/*		PARSER.C			*/

int		zap_spaces(char **line);
int		first_word(char **str, t_parsing_list *l);
int		parser(char **line, t_parsing_list *l);
int		maestro(char *line);

/*	init_parsing_list.c	*/
int		init_parsing_list(t_parsing_list **l);
void	init_parsing_node(t_parsing_node *node);
t_parsing_list	*list_end_parse(t_parsing_list *list, char *content);
void	display_parsing(t_parsing_list *l);
#endif
