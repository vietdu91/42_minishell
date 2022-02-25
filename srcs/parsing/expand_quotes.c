/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:08:53 by emtran            #+#    #+#             */
/*   Updated: 2022/02/24 10:21:15 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	wid_with_dq(char **str, int len, t_pars_node *parser, t_env_list *env)
{
	strjoin_c_content_exp(str, parser);
	while (**str != '\"')
	{
		if (**str == '$' && *(*str + 1) != '"')
			strjoin_content_exp(str, len, parser, env);
		else
			strjoin_c_content_exp(str, parser);
	}
	strjoin_c_content_exp(str, parser);
}

void	strjoin_c_content_exp(char **str, t_pars_node *parser)
{
	char	content;

	content = **str;
	parser->content_exp = ft_strjoin_one_c(parser->content_exp, content);
	(*str)++;
}

void	strjoin_content_exp(char **str, int len, t_pars_node *psr, \
t_env_list *env)
{
	char	*var;
	char	*content;

	var = NULL;
	content = NULL;
	var = check_variable(str, len);
	content = put_content_of_expand(var, env);
	psr->content_exp = ft_strjoin(psr->content_exp, content);
	free(content);
	free(var);
}

void	convert_expand_quotes(t_pars_node *parser)
{
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	len = check_len_new_word(parser->content_exp);
	parser->content_exp_sans_q = malloc(sizeof(char) * (len + 1));
	while (parser->content_exp[i])
	{
		if (is_quote(parser->content_exp[i]) == 1)
			put_content_exp_sans_q(parser, &i, &j, '\'');
		else if (is_quote(parser->content_exp[i]) == 2)
			put_content_exp_sans_q(parser, &i, &j, '\"');
		else
			parser->content_exp_sans_q[j++] = parser->content_exp[i++];
	}
	parser->content_exp_sans_q[j] = 0;
}
