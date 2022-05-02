/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:40:50 by emtran            #+#    #+#             */
/*   Updated: 2022/02/14 16:35:58 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

/*		SIGNAL.C		*/

void	signal_ctlr_c(int signal);
void	ignore_signals(void);
void	recover_signals(void);
void	handle_status(int sig);

#endif