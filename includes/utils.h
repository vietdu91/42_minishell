/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:44:03 by emtran            #+#    #+#             */
/*   Updated: 2021/12/30 19:02:19 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*	UTILS_STRINGS 	*/

void		ft_putstr(char *str, int fd);
void		ft_putchar(char c, int fd);
int			ft_strlen(char *str);

/* 	UTILS_DIGITS 	*/

void		ft_putnbr(int nb, int fd);
long int	ft_atoi(const char *str);
int			ft_nbrlen(int n);

#endif