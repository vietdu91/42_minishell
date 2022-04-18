/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:30:42 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/17 17:16:47 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/*		ATTRIBUTION.C		*/

int		check_if_meta(t_pars_list *l);
int		logical_attribution(t_pars_list *l);

/*		ATTRIBUTION_NORM.C	*/

void	apply_cmd(t_pars_node *node, int type);
int		apply_type(int type, t_pars_node *node);

/*		ATTRIBUTION_META.C	*/
int		logical_attribution(t_pars_list *l);
int		check_if_meta(t_pars_list *l);

/*		LEXER_EXPAND.C		*/
int	split_expand(t_pars_list *l, t_env_list *env);

/*		LEXER_MAESTRO		*/
int		lexer_maestro(t_args *args);

/*		LEXER_UTILS.C		*/
int		check_enum(int n);
void	hdocs_is_valid(t_pars_node *node);
void	norm_heredoc(t_pars_node *node);
int		forbidden_token(t_pars_list *l);

#endif