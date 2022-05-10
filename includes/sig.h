/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:40:50 by emtran            #+#    #+#             */
/*   Updated: 2022/05/09 10:16:59 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

/*		HANDLERS.C		*/

void	signal_ctlr_c(int signal);
void	signal_exec(int signal);
void	signal_segfault(int signal);
void	signal_ignore(int signal);
void	signal_heredoc(int signal);

/*		SIGNAL.C		*/

void	all_ignore(void);

#endif