/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:12:01 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 18:48:07 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define BASH "bash: "
# define CMD_CD "cd: "
# define CMD_ENV "env: "
# define CMD_EXIT "exit: "
# define CMD_EXPORT "export: "
# define CMD_PWD "pwd: "
# define CMD_UNSET "unset: "
# define ERR_CMD "command not found\n"
# define ERR_DIR "No such file or directory\n"
# define ERR_HOME "HOME not set\n"
# define ERR_ID "not a valid identifier\n"
# define ERR_MALLOC "Failed to allocate memory.\n"
# define ERR_MANY_ARG "too many arguments\n"
# define ERR_NOENV "No such environment\n"
# define ERR_OLDPWD_NOTSET "OLDPWD not set\n"
# define ERR_OPTION "invalid option\n"
# define ERR_STALE "Stale file handle\n"
# define ERR_TOKEN "bash: syntax error near unexpected token `"
# define ERR_UNCLOSED "bash: syntax error: unclosed quotes `"

/*		PRINT_ERROR.C		*/

void	intersection_of_errors(int a, t_args *args);
void	print_error_and_exit(char *msg_error, t_args *args);
void	print_syntax_error(char *msg_error, char *sign);
void	print_error(char *sys, char *cmd, char *arg, char *error);
void	print_error_w_quote(char *sys, char *cmd, char *arg, char *error);

/*		INVALID_OPTION.C	*/

void	invalid_option(t_pars_node *node, char *cmd);

#endif