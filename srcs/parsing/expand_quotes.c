/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:08:53 by emtran            #+#    #+#             */
/*   Updated: 2022/02/13 18:42:49 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	convert_expand_quotes(t_pars_list *parser)
{
	t_pars_node	*node;
	int			i;
	int			j;
	int			len;

	i = 0;
	j = 0;
	node = NULL;
	node = parser->head;
	while (node)
	{
		len = check_len_new_word(node->content_exp);
		node->content_exp_sans_q = malloc(sizeof(char) * (len + 1));
		while (node->content_exp[i])
		{
			if (is_quote(node->content_exp[i]) == 1)
			{
				i++;
				while (node->content_exp[i] != '\'')
					node->content_exp_sans_q[j++] = node->content_exp[i++];
				i++;
			}
			else if (is_quote(node->content_exp[i]) == 2)
			{
				i++;
				while (node->content_exp[i] != '\"')
					node->content_exp_sans_q[j++] = node->content_exp[i++];
				i++;
			}
			else
				node->content_exp_sans_q[j++] = node->content_exp[i++];
		}
		node = node->next;
	}
}