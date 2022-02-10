/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:41:56 by emtran            #+#    #+#             */
/*   Updated: 2022/02/10 20:03:20 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	len_of_variable(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			if (is_digit(str[i]))
			{
				count++;
				break ;
			}
			while (is_alphanum(str[i]) || str[i] == '_')
			{
				count++;
				i++;
			}
			break ;
		}
		else
			i++;
	}
	return (count);
}

char	*check_variable(char *str, t_args *args)
{
	int	i;

	(void) args;
	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
		//	while (is_alphanum(str[i]) || str[i] == '_')
		//	{
		//		
		//	}
		}
		i++;
	}
	return (str);
}

char	*where_is_dollar(char *str, t_env_list *env)
{
	int		i;
	char	*var;

	(void) env;
	i = 0;
	var = NULL;
	i = len_of_variable(str);
	printf("I : %d\n", i);
	return (var);
//	var = check_variable(str, args);
}

void	expand(char **str, t_pars_node *parser, t_args *args)
{
	char	*cpy;
	char	*var;

	(void) parser;
	cpy = *str;
	var = where_is_dollar(cpy, args->env);
	return ;
}
