/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:41:56 by emtran            #+#    #+#             */
/*   Updated: 2022/03/01 16:47:09 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_the_len_of_variable(int *count, int *i, char *str)
{
	if (str[*i + 1] == '$' || str[*i + 1] == '\0' || is_quote(str[*i + 1]) \
	|| !is_alphanum(str[*i + 1]))
	{
		(*count)++;
		if (str[*i + 1] != '\0')
		{
			if (is_quote(str[*i + 2]))
				(*count)++;
		}
		return ;
	}
	(*i)++;
	if (is_digit(str[*i]) || str[*i] == '?')
	{
		(*count)++;
		return ;
	}
	while (is_alphanum(str[*i]) || str[*i] == '_')
	{
		(*i)++;
		(*count)++;
	}
}

int	len_of_variable(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			count_the_len_of_variable(&count, &i, str);
			break ;
		}
		else
			i++;
	}
	return (count);
}

char	*check_variable(char **str, int len)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	j = 0;
	var = NULL;
	while (j++ < len)
	{
		if (**str == '$')
		{
			i = len_of_variable(*str);
			if (*(*str + 1) == '?')
				(*str)++;
			else if (*(*str + 1) != '$' && ft_strcmp("$", *str) \
			&& !is_quote(*(*str + 1)) && (is_alphanum(*(*str + 1)) == 1))
				(*str)++;
			else if (is_quote(*(*str + 1)) && is_quote(*(*str + 2)))
				(*str)++;
			var = malloc(sizeof(char) * (i + 1));
			ft_strncpy(var, *str, i);
			while (i-- > 0)
				(*str)++;
			return (var);
		}
	}
	return (var);
}

void	where_is_dollar(char **str, t_pars_node *parser, t_env_list *env)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(*str);
	while (**str && i++ < len)
	{
		if (is_quote(**str) == 1)
		{
			strjoin_c_content_exp(str, parser);
			while (**str != '\'')
				strjoin_c_content_exp(str, parser);
			strjoin_c_content_exp(str, parser);
		}
		else if (is_quote(**str) == 2)
			wid_with_dq(str, len, parser, env);
		else if (**str == '$' && is_quote(*(*str + 1)))
			(*str)++;
		else if (**str == '$')
			strjoin_content_exp(str, len, parser, env);
		else
			strjoin_c_content_exp(str, parser);
	}
	return ;
}

void	expand(char *str, t_pars_node *parser, t_env_list *env)
{
	// int		i;
	char	**cpy;

	if (!str)
		return ;
	// i = 0;
	cpy = &str;
	where_is_dollar(cpy, parser, env);
	convert_expand_quotes(parser);
	return ;
}
