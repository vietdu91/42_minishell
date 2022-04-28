/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:30:42 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/21 19:28:55 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/*		ATTRIBUTION_META.C	*/

int		attribution_metachar(t_pars_node *node);
int		find_if_error(t_pars_node *node);
int		check_if_meta(t_pars_list *l);
int		attribute_meta(t_pars_node *node);
int		logical_attribution(t_pars_list *l);

/*		ATTRIBUTION_NORM.C	*/

void	apply_cmd(t_pars_node *node, int type);
int		apply_type(int type, t_pars_node *node);

/*		LEXER_EXPAND.C		*/

int		content_is_to_split(char *content);
char	*return_var(char *str, t_env_list *env, int datas[2]);
int		split_to_node(char *str, t_pars_list *list, t_pars_node *node, \
t_env_list *env);
int		loop_var(char *str, t_pars_list *l, t_env_list *env, t_pars_node *node);
int		split_expand(t_pars_list *l, t_env_list *env);

/*		LEXER_MAESTRO		*/

int		syntax_error_meta(t_args *args);
void	cmd_or_option_or_arg(t_pars_node *i, int cmd);
void	cmd_attribution(t_pars_list *l);
void	split_meta(t_pars_list *l);
int		lexer_maestro(t_args *args);

/*		LEXER_UTILS.C		*/

int		check_enum(int n);
void	hdocs_is_valid(t_pars_node *node);
void	norm_heredoc(t_pars_node *node);
int		is_forbidden(t_pars_node *node);
int		forbidden_token(t_pars_list *l);

#endif