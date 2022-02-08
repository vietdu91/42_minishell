/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:30:42 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/07 23:54:21 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/*		ATTRIBUTION.C		*/

int		check_if_meta(t_pars_list *l);
int		logical_attribution(t_pars_list *l);

/*		ATTRIBUTION_NORM.C	*/

void	apply_cmd(t_pars_node *node);

/*		ATTRIBUTION_META.C	*/
int		logical_attribution(t_pars_list *l);
int		check_if_meta(t_pars_list *l);

/*		LEXER_MAESTRO		*/
int		lexer_maestro(t_args *args);

#endif