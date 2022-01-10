/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2022/01/10 19:47:12 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTIN_H
# define BULTIN_H

typedef struct s_env
{
	int	env_on;
}	t_env;

typedef struct s_pwd
{
	int	pwd_on;
}	t_pwd;

typedef struct s_history
{
	int	history_on;
}	t_history;

typedef struct s_exit
{
	int	exit_on;
	char*	nb;
	char*	other_nb;
}	t_exit;

typedef struct s_export
{
	int	export_on;
	char*	var;
	char*	value;
}	t_export;

typedef struct s_unset
{
	int	unset_on;
	char*	var;
}	t_export;

typedef struct s_cd
{
	int	cd_on;
	char	*path;
}	t_cd;

typedef struct s_echo
{
	int	echo_on;
	int	option_n;
	char	*str;
}	t_echo;
#endif
