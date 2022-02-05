/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:10 by emtran            #+#    #+#             */
/*   Updated: 2022/02/05 22:46:22 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

enum	e_type
{
	EMPTY,
	ERROR,
	CMP,
	CMD,
	SIMPLE_ARG,
	PIPE,
	DOUBLE_PIPE,
	LOGICAL_AND,
	ASTERISQUE,
	CONTINUE,
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

typedef struct s_pars_node
{
	char				*content;
	enum e_type			type;
	struct s_pars_node	*previous;
	struct s_pars_node	*next;
}	t_pars_node;

typedef struct s_pars_list
{
	t_pars_node	*head;
	t_pars_node	*tail;
	int			length;
}	t_pars_list;

typedef struct s_builtin
{
	int		oldpwd_on;
	char	*oldpwd;
}	t_builtin;


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
	int				len_content;
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
	t_pars_list		*parser;
	char			*buffer;
	char			*path;
	char			*pwd;
	char			*home;
	int				quote_parse;
	int				nb_commands;
}	t_args;

/*		FIND_IN_ENV.C		*/

char	*find_path(char **envp);
char	*find_pwd(char **envp);
char	*find_oldpwd(char **envp);
char	*find_home(char **envp);

/*		PARSER_QUOTES.C			*/

int		check_len_word_in_quotes(char quote, char *str, int pos, int count);
void	cpy_with_double_quotes(size_t *i, size_t *j, char *dest, char *src);
int		count_words_with_quotes(char *s, int *count, int i, char quote);
int		size_word_with_quotes(char *s, t_args *args, char quote);

/*		PARSER_WORDS.C			*/
int		cut_content(t_pars_list *l, t_args *args);
int		word_has_meta(char *content);
int		check_len_word(char *str);
char	*put_word_to_content(char **str, char *content);
int		find_word(char **str, t_pars_list *parser);

/*		PARSER.C			*/
int		zap_spaces(char **line);
int		parser(char **line, t_pars_list *parser, t_args *args);
int		maestro(t_args *args, char *line);

/*		ATTRIBUTION.C		*/
int		check_if_meta(t_pars_list *l);
int		logical_attribution(t_pars_list *l);

/*		ATTRIBUTION_NORM.C	*/
void	apply_cmd(t_pars_node *node);

#endif
