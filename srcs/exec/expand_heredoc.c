/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:27:18 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/15 16:04:39 by dyoula           ###   ########.fr       */
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

char	*send_variable(char *line, t_env_list *env)
{
	char	*flag;
	char	*var;
	char	*content;

	var = ft_strdup("");
	content = ft_strdup("");
	flag = ft_strdup("");
	// printf("line : %s\n", line);
	while (*line)
	{
		if (line && *line == '$')
		{
			var = check_variable(&line, ft_strlen(line));
			// printf("VAR : %s\n", var);
			content = put_content_trim_of_expand(var, env);
			// printf("CONTENT : %s\n", content);
			flag = ft_strjoin(flag, content);
			// printf("FLAG = %s\n", flag);
			free(var);
			free(content);
		}
		flag = ft_strjoin_one_c(flag, *line);
		(line)++;
	}
	flag = ft_strjoin_one_c(flag, '\n');
	return (flag);
}

char	*split_to_join(char **d_tab)
{
	char	*string;
	char	*cpy;
	int		i;
	int		j;
	int		k;
	
	string = NULL;
	cpy = ft_strdup("");
	i = 0;
	while (d_tab[i])
	{
		// printf("d_tab 0 : %s\n", d_tab[i]);
		string = malloc(sizeof(char) * (ft_strlen(cpy) + ft_strlen(d_tab[i]) + 1));
		j = 0;
		while (cpy[j])
			j++;
		k = 0;
		// printf("STRING 3 : %s\n", string);
		while (d_tab[i][k])
		{
			string[j] = d_tab[i][k];
			// printf("d_tab : %c\n", d_tab[i][k]);
			// printf("lol : %c\n", string[j]);
			j++;
			k++;
		}
		string[j] = '\0';
		free(cpy);
		cpy = ft_strdup(string);
		free(string);
		i++;
	}
	return (cpy);
}

int	modify_heredoc(char **hdoc, char **limitator, t_env_list *env)
{
	// 1 splitter par les \n 
	// checker chaque tab 
	// if $ agir comme fonction expand
	// checker si le limitator a des quotes
	char	**d_tab;
	int		i;
	int		j;

	j = 0;
	i = -1;
	// find which is the good limitator
	if (!hdoc)
		return (0);
	while (hdoc[j])
		j++;
	if (quotes_or_not(*limitator))
		return (-1);
	j = 0;
	d_tab = NULL;
	d_tab = ft_split(hdoc[j], '\n');
	if (!d_tab)
		return (-1);
	free(hdoc[j]);
	while (d_tab[++i])
	{
		d_tab[i] = send_variable(d_tab[i], env);
		// printf("DTAB[%d] : %s\n", i, d_tab[i]);
	}
	hdoc[j] = split_to_join(d_tab);
	// modifier strcmp 
	return (0);
}
