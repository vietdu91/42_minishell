/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:27:18 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/08 20:10:36 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

int	quotes_or_not(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (is_quote(str[i]))
			return (1);
	return (0);
}

int	send_variable(char *line, char *limitator, t_env_list *env)
{
	char	*flag;
	char	*var;
	char	*content;

	var = NULL;
	content = NULL;
	flag = NULL;
	while (line)
	{
		while (*line != '$')
		{
			flag = ft_strjoin_one_c(flag, *line);
			(*line)++;
		}
		if (*line == '$')
		{
			var = check_variable(flag, ft_strlen(flag));
			content = put_content_trim_of_expand(var, env);
			flag = ft_strjoin(flag, content);
			free(var);
			free(content);
		}
	}
}
int	modify_heredoc(char **hdoc, char **limitator, t_env_list *env)
{
	// 1 splitter par les \n 
	// checker chaque tab 
	// if $ agir comme fonction expand
	// checker si le limitator a des quotes
	char	**d_tab;
	int		i;

	i = -1;
	// find which is the good limitator
	if (quotes_or_not(limitator))
		return (-1);
	d_tab = ft_split(hdoc, '\n');
	d_tab = NULL;
	if (d_tab)
		return (-1);
	
	while (d_tab[++i])
	{
		send_variable(d_tab[i], limitator, env);
		
	}
	return (0);
}
