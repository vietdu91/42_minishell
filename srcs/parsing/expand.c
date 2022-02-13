/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:41:56 by emtran            #+#    #+#             */
/*   Updated: 2022/02/13 18:43:40 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

char	*put_content_of_expand(char *var, t_env_list *env)
{
	t_env	*node;
	char	*content;

	node = NULL;
	node = env->head;
	content = NULL;
	while (node)
	{
		if (!ft_strcmp(var, node->variable))
		{
			content = ft_strdup(node->content);
			return (content);
		}
		node = node->next;
	}
	return ("");
}

void	where_is_dollar(char **str, t_pars_node *parser, t_args *args)
{
	int		i;
	int		len;
	int		quote;
	char	*var;
	char	*content;

	i = 0;
	quote = 0;
	var = NULL;
	content = NULL;
	len = ft_strlen(*str);
	while (**str && i++ < len)
	{
		if (is_quote(**str) == 1)
		{
			quote = 1;
			parser->content_exp = ft_strjoin_one_c(parser->content_exp, **str);
			(*str)++;
			while (**str != '\'')
			{
				parser->content_exp = ft_strjoin_one_c(parser->content_exp, **str);
				(*str)++;
			}
			parser->content_exp = ft_strjoin_one_c(parser->content_exp, **str);
			(*str)++;
			quote = 0;
		}
		else if (is_quote(**str) == 2)
		{
			quote = 2;
			parser->content_exp = ft_strjoin_one_c(parser->content_exp, **str);
			(*str)++;
			while (**str != '\"')
			{
				if (**str == '$')
				{
					var = check_variable(str, len);
					content = put_content_of_expand(var, args->env);
					parser->content_exp = ft_strjoin(parser->content_exp, content);
					free(var);
				}
				else
				{
					parser->content_exp = ft_strjoin_one_c(parser->content_exp, **str);
					(*str)++;
				}
			}
			parser->content_exp = ft_strjoin_one_c(parser->content_exp, **str);
			(*str)++;
			quote = 0;
		}
		else if (**str == '$')
		{
			var = check_variable(str, len);
			content = put_content_of_expand(var, args->env);
			parser->content_exp = ft_strjoin(parser->content_exp, content);
			free(var);
		}
		else
		{
			parser->content_exp = ft_strjoin_one_c(parser->content_exp, **str);
			(*str)++;
		}
	}
	return ;
}

void	expand(char *str, t_pars_node *parser, t_args *args)
{
	int		i;
	char	**cpy;

	if (!str)
		return ;
	i = 0;
	cpy = &str;
	where_is_dollar(cpy, parser, args);
	convert_expand_quotes(args->parser);
	return ;
}
