/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:27:18 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/06 14:56:34 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*strjoin_content_exp_hdoc(char **str, int len, char *flag, \
t_env_list *env)
{
	char	*var;
	char	*content;

	var = NULL;
	content = NULL;
	var = check_variable(str, len);
	content = put_content_of_expand_sans_check(var, env);
	flag = ft_strjoin(flag, content);
	free(content);
	free(var);
	return (flag);
}

int	quotes_or_not(char *str)
{
	int	i;

//	printf("STR : %s\n", str);
	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (is_quote(str[i]))
			return (1);
	// printf("lol\n");
	return (0);
}

char	*send_variable(char *line, t_env_list *env)
{
	char	*cpy;
	char	*flag; // variable a return
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(line);
	flag = NULL;
	cpy = line;
	(void)i;
	while (*cpy)
	{
		if (*cpy)
		{
			if (*cpy == '$')
				flag = strjoin_content_exp_hdoc(&cpy, len, flag, env);
			else
			{
				flag = ft_strjoin_one_c(flag, *cpy);
				cpy++;
			}
		}
	}
	free(line);
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
	i = 0;
	k = 0;
	while (d_tab[i])
	{
		j = 0;
		while (d_tab[i][j++])
		{
			// printf("TOTAL : %d \n", k);
			// printf("[i][j]%d\n", d_tab[i][j]);
			k++;
		}
		i++;
	}
	string = malloc(sizeof(char) * (k + 1));
	i = 0;
	j = 0;
	while (d_tab[i])
	{
		k = 0;
		while (d_tab[i][k])
		{
			string[j] = d_tab[i][k];
			// printf("d_tab : %c\n", d_tab[i][k]);
			// printf("J : %d et String : %c\n", j, string[j]);
			j++;
			k++;
		}
		i++;
	}
		// printf("lol : %s\n", string);
		string[j] = '\0';
		cpy = ft_strdup(string);
		free(string);
	return (cpy);
}

int	modify_heredoc(char **hdoc, char *limitator, t_env_list *env)
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
	if (!hdoc || !limitator)
		return (0);
	while (hdoc[j])
	{
		j++;
	}
	if (quotes_or_not(limitator))
		return (-1);
	j = 0;
	d_tab = NULL;
	d_tab = ft_split(hdoc[j], '\n');
	if (!d_tab)
		return (-1);
	// return (0);
	free(hdoc[j]);
	while (d_tab[++i])
		d_tab[i] = send_variable(d_tab[i], env);
	hdoc[j] = NULL;
	hdoc[j] = split_to_join(d_tab);
	free_d_tab(d_tab);
	d_tab = NULL;
	return (0);
}
