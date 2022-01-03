/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:55:25 by emtran            #+#    #+#             */
/*   Updated: 2022/01/03 13:38:12 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* readline - Fcts rl_* - printf - perror */
# include <stdio.h>
/* malloc - free - exit - getenv */
# include <stdlib.h>
/* write - access - read - close - fork - getcwd - chdir - stat - lstat 
fstat - unlink - execve - dup - dup2 - pipe - isatty - ttyname - ttyslot 
tcsetattr - tcgetattr */
# include <unistd.h>
/* signal - sigaction - kill */
# include <signal.h>
/* opendir - readdir - closedir */
# include <dirent.h>
/* open */
# include <fcntl.h>
/* strerror */
# include <string.h>
/* tcsetattr - tcgetattr */
# include <termios.h>
/* tgetent - tgetflag - tgetnum - tgetstr - tgoto - tputs */
# include <curses.h>
# include <term.h>
/* readline - Fcts rl_* - add_history */
# include <readline/readline.h>
# include <readline/history.h>
/* open - wait - waitpid - kill - stat - lstat - fstat - opendir - closedir */
# include <sys/types.h>
/* open - stat - lstat - fstat */
# include <sys/stat.h>
/* wait - waitpid - wait3 - wait4 */
# include <sys/wait.h>
/* wait3 - wait4 */
# include <sys/time.h>
# include <sys/resource.h>
/* ioctl */
# include <sys/ioctl.h>

# include "./parsing.h"
# include "./utils.h"

#endif