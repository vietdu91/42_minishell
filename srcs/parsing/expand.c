/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 16:41:56 by emtran            #+#    #+#             */
/*   Updated: 2022/05/17 18:07:58 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
			strjoin_content_trim_exp(str, len, parser, env);
		else
			strjoin_c_content_exp(str, parser);
	}
	return ;
}

void	expand(char *str, t_pars_node *parser, t_env_list *env)
{
	char	**cpy;

	if (!str)
		return ;
	cpy = &str;
	where_is_dollar(cpy, parser, env);
	convert_expand_quotes(parser);
	if (parser->check_in == TRUE)
	{
		parser->content_exp = decheck_quotes_in_content(parser->content_exp);
		parser->content_exp_sans_q = \
		decheck_quotes_in_content(parser->content_exp_sans_q);
	}
	return ;
}
