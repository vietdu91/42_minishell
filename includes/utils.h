/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:44:03 by emtran            #+#    #+#             */
/*   Updated: 2022/01/03 16:36:19 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*		UTILS_STRINGS 	*/

int			ft_strlen(char *str);
int			ft_strcmp(char *str1, char *str2);
void		ft_strcpy(char *dest, char *src);
char		*ft_strjoin(char *s1, char *s2);

/* 		UTILS_DIGITS 	*/

long int	ft_atoi(const char *str);
int			ft_nbrlen(int n);

/* 		UTILS_WRITE 	*/

void		ft_putnbr(int nb, int fd);
void		ft_putstr(char *str, int fd);
void		ft_putchar(char c, int fd);

#endif