/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_many.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:26:44 by emtran            #+#    #+#             */
/*   Updated: 2022/02/10 18:01:14 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	how_many_pipes(char *str)
{
	int	a;
	int	pipes;

	a = -1;
	pipes = 0;
	while (str[++a])
	{
		if (str[a] == '|' && str[a + 1] != '|')
			pipes++;
		if (str[a] == '|' && str[a + 1] == '|')
			a++;
	}
	return (pipes);
}

int	how_many_double_pipes(char *str)
{
	int	a;
	int	db_pipes;

	a = 0;
	db_pipes = 0;
	while (str[a])
	{
		if (str[a] == '|' && str[a + 1] != '|')
			a++;
		else if (str[a] == '|' && str[a + 1] == '|')
		{
			db_pipes++;
			a++;
		}
		if (str[a])
			a++;
	}
	return (db_pipes);
}

int	how_many_double_appersand(char *str)
{
	int	a;
	int	db_apper;

	a = -1;
	db_apper = 0;
	while (str[++a])
	{
		if (str[a] == '&' && str[a + 1] == '&')
		{
			db_apper++;
			a++;
		}
	}
	return (db_apper);
}

int	how_many_commands(char *str)
{
	int	nb_cmd;

	nb_cmd = how_many_pipes(str);
	nb_cmd += how_many_double_pipes(str);
	nb_cmd += how_many_double_appersand(str);
	return (nb_cmd + 1);
}
