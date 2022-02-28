/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:12:01 by emtran            #+#    #+#             */
/*   Updated: 2022/02/28 14:51:31 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define ERR_NOENV "No such environment\n"
# define ERR_MALLOC "Failed to allocate memory.\n"
# define ERR_UNCLOSED "bash: syntax error: unclosed quotes `"
# define ERR_MANY_ARG "bash: exit: too many arguments\n"
# define ERR_TOKEN "bash: syntax error near unexpected token `"

/*		ERRORS.C		*/

void	intersection_of_errors(int a, t_args *args);
void	print_error(char *msg_error, t_args *args);
void	print_syntax_error(char *msg_error, char *sign);

#endif