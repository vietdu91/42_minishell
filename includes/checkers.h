/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:37:14 by emtran            #+#    #+#             */
/*   Updated: 2022/01/31 16:30:10 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERS_H
# define CHECKERS_H

# define DIGITS "0123456789"
# define LOW_ALPHA "abcdefghijklmnopqrstuvwxyz"
# define UPP_ALPHA "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define SPACES " \f\r\t\v" // newline non inlus
# define METACHAR "|&;<>"
// # define METACHAR "|&;()<>"

/*		HOW_MANY.C			*/

int	how_many_pipes(char *str);
int	how_many_double_pipes(char *str);
int	how_many_double_appersand(char *str);
int	how_many_commands(char *str);

/*		IS_ALPHANUM.C		*/

int	is_alpha(char c);
int	is_upper(char c);
int	is_lower(char c);
int	is_alphanum(char c);

/*		IS_OTHERS.C		*/

int	is_digit(char c);
int	is_space(char c);
int	is_meta(char c);
int	is_quote(char c);
int	how_many_pipes(char *str);

/*		IS_UNCLOSED.C			*/

int	check_unclosed(t_args *args);
int	is_unclosed_quotes(char *str);
int	is_unclosed_parenth(char *str);

#endif