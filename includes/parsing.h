/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:37:14 by emtran            #+#    #+#             */
/*   Updated: 2022/01/03 14:50:49 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# define DIGITS "0123456789"
# define LOW_ALPHA "qwertyuiopasdfghjklzxcvbnm"
# define UPP_ALPHA "QWERTYUIOPASDFGHJKLZXCVBNM"
# define SPACES " \f\n\r\t\v"

/*		IS_WHAT_STR.C		*/

int	is_alpha(char c);
int	is_upper(char c);
int	is_lower(char c);
int	is_alphanumeric(char c);

/*		IS_WHAT_OTHERS.C		*/

int	is_digit(char c);
int	is_space(char c);

#endif