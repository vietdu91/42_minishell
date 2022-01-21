/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:44:03 by emtran            #+#    #+#             */
/*   Updated: 2022/01/21 13:59:58 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define BUFFER_SIZE 1

/* 		UTILS_DIGITS 	*/

long int	ft_atoi(const char *str);
int			ft_nbrlen(int n);

/*		UTILS_LINKED	*/

t_list		*init_list(void);
t_list		*list_end(t_list *list, char *content);

/*		UTILS_MEMORY	*/

void		*ft_memcpy(void *dest, const void *src, size_t count);
char		*ft_strcalloc(size_t size);

/* 		UTILS_SPLIT 	*/

size_t		ft_wordcount(char const *s, char c);
size_t		ft_wordlen(char const *s, char c);
char		**ft_freetamere(char **array);
char		**ft_split(char const *s, char c);

/*		UTILS_STRINGS 	*/

int			ft_strlen(char *str);
int			ft_strcmp(char *str1, char *str2);
void		ft_strcpy(char *dest, char *src);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strnstr(char *s1, const char *s2, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(char *str);

/* 		UTILS_WRITE 	*/

void		ft_putnbr(int nb, int fd);
void		ft_putstr(char *str, int fd);
void		ft_putchar(char c, int fd);

#endif