/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2022/01/13 15:33:36 by emtran           ###   ########.fr       */
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
	int		exit_on;
	int		nb;
}	t_exit;

typedef struct s_export
{
	int		export_on;
}	t_export;

typedef struct s_unset
{
	int		unset_on;
}	t_unset;

typedef struct s_cd
{
	int		cd_on;
}	t_cd;

typedef struct s_echo
{
	int		echo_on;
	int		option_n;
}	t_echo;
#endif
