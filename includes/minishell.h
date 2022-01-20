/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:55:25 by emtran            #+#    #+#             */
/*   Updated: 2022/01/20 16:35:22 by dyoula           ###   ########.fr       */
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
# include <errno.h>

# include "./checkers.h"
# include "./fun.h"
# include "./parsing.h"
# include "./sig.h"
# include "./utils.h"
# include "./errors.h"
# include "./memory.h"

# define PROMPT "\033[5;91mWELCOME TO THE (minis)HELL 😈 \e[0m\033[1;93m$> \e[0m"

extern int	g_exit_status;

/*		MAIN.C		*/

void	loop(char **envp, t_args *args);
void	cmp_all(t_args *args, char **envp);

#endif