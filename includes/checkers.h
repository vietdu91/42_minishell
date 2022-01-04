/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:37:14 by emtran            #+#    #+#             */
/*   Updated: 2022/01/04 13:48:36 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKERS_H
# define CHECKERS_H

# define DIGITS "0123456789"
# define LOW_ALPHA "qwertyuiopasdfghjklzxcvbnm"
# define UPP_ALPHA "QWERTYUIOPASDFGHJKLZXCVBNM"
# define SPACES " \f\r\t\v" // newline non inlus
# define METACHAR "|&;()<>"

/*		IS_WHAT_ALPHANUM.C		*/

int	is_alpha(char c);
int	is_upper(char c);
int	is_lower(char c);
int	is_alphanum(char c);

/*		IS_WHAT_OTHERS.C		*/

int	is_digit(char c);
int	is_space(char c);
int	is_meta(char c);

#endif