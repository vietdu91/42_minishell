/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_maestro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 14:03:48 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	syntax_error_meta(t_args *args)
{
	t_pars_node	*i;

	i = args->parser->head;
	if (!i)
		return (-1);
	if (is_pipe_or_wrong(i->type))
		return (print_syntax_error_meta(i->content_exp_sans_q));
	while (i && i->next)
	{
		if (i->type == WRONG_META)
			return (print_syntax_error_meta(i->content_exp_sans_q));
		else if (check_enum(i->type) && check_enum(i->next->type))
			return (print_syntax_error_meta(i->next->content_exp_sans_q));
		i = i->next;
	}
	if (check_enum(i->type))
		return (print_syntax_error_meta(i->content_exp_sans_q));
	return (1);
}

void	cmd_or_option_or_arg(t_pars_node *i, int *cmd)
{
	if (i->previous && i->previous->type == CMD)
		*cmd = 1;
	if (i->type == EMPTY && *cmd == 1)
		i->type = SIMPLE_ARG;
	if (*cmd == 0 && i->type == EMPTY)
		i->type = CMD;
	if (i->previous && (i->previous->type == CMD \
	|| i->previous->type == OPTION) && i->content[0] == '-' \
		&& i->content[1] != 0)
		i->type = OPTION;
	if (i->type == PIPE)
		*cmd = 0;
}

void	cmd_attribution(t_pars_list *l)
{
	t_pars_node	*i;
	int			cmd;

	cmd = 0;
	i = l->head;
	if (!i)
		return ;
	if (i->type == 0)
		i->type = CMD;
	if (i && i->next == NULL)
		return ;
	i = i->next;
	while (i)
	{
		cmd_or_option_or_arg(i, &cmd);
		i = i->next;
	}
}

void	split_meta(t_pars_list *l)
{
	t_pars_node	*i;

	i = l->head;
	while (i)
	{
		if (is_full_meta(i->content) && ft_strlen(i->content) > 1)
			splitter_content_meta(i, l);
		i = i->next;
	}
}

int	lexer_maestro(t_args *args)
{
	if (!args->parser)
		return (0);
	logical_attribution(args->parser);
	cmd_attribution(args->parser);
	if (syntax_error_meta(args) < 0 || forbidden_token(args->parser))
		return (-1);
	return (0);
}
