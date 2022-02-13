/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:10 by emtran            #+#    #+#             */
/*   Updated: 2022/02/13 18:36:41 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

enum	e_type
{
	EMPTY,	// 0
	ERROR,	// 1
	CMP,	// 2
	CMD,	// 3
	OPTION_CMD, // 4
	SIMPLE_ARG,	// 5
	PIPE,	// 6
	DOUBLE_PIPE,	// 7
	LOGICAL_AND,	// 8
	ASTERISQUE,		// 9
	CONTINUE,		// 10
/*		<		*/
	INPUT,	// 11
	INFILE,	// 12
/*		>		*/
	OUTPUT,	// 13
	OUTFILE,	// 14
/*		>>		*/
	SUPER_OUTPUT,	// 15
	SUPER_OUTFILE,	// 16
/*		<<		*/
	HEREDOC,	// 17
	LIMITATOR,	// 18
/*		||>		*/
	WRONG_META, //19
	OPTION, // 20
};

typedef struct s_pars_node
{
	char				*content;
	char				*nw_content;
	char				*content_exp;
	char				*content_exp_sans_q;
	enum e_type			type;
	int					*index_crypted;
	char				*path;
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

typedef struct s_env
{
	char			*line;
	char			*variable;
	char			*content;
	int				len_content;
	char			*path;
	enum e_var		var_id;
	struct s_env	*next;
}	t_env;

typedef struct s_env_list
{
	t_env	*head;
	t_env	*tail;
	int		length;
}	t_env_list;

typedef struct s_args
{
	t_builtin		*builtin;
	t_env_list		*env;
	t_env_list		*export;
	t_pars_list		*parser;
	char			*buffer;
	char			*path;
	char			*path_to_try;
	char			*final_path;
	char			*pwd;
	char			*home;
	int				quote_parse;
	int				nb_commands;
}	t_args;

/*		CRYPTING_PARSER_QUOTES.C	*/

int		fill_crypt_tab(char *str, t_pars_node *parser);
void	crypt_content(char *str, int size, t_pars_node *parser);
void	decrypt_content(char *str, int size, t_pars_node *parser);
int		encrypting(char *str, t_pars_node *parser);

/*		EXPAND_QUOTES.C		*/

void	convert_expand_quotes(t_pars_list *parser);

/*		EXPAND.C			*/

int		len_of_variable(char *str);
char	*check_variable(char **str, int len);
char	*put_content_of_expand(char *var, t_env_list *env);
void	where_is_dollar(char **str, t_pars_node *parser, t_args *args);
void	expand(char *str, t_pars_node *parser, t_args *args);

/*		FIND_IN_ENV.C		*/

char	*find_path(char **envp);
char	*find_pwd(char **envp);
char	*find_oldpwd(char **envp);
char	*find_home(char **envp);

/*		PARSER_CONVERT.C		*/

char	*put_new_word_to_content(char **str, char *content);
int		check_len_nw_word_in_quotes(char quote, char *str, int *pos, int count);
int		check_len_new_word(char *str);
void	convert_content_without_quotes(char **str, t_pars_node *parser);

/*		PARSER_QUOTES.C			*/

int		find_meta_in_quotes(char *str);
int		check_len_word_in_quotes(char quote, char *str, int *pos, int count);
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
int		parser(char **line, t_pars_list *psr, t_args *args);
int		parsing_maestro(t_args *args, char *line);

#endif
