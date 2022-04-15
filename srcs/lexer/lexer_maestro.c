/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_maestro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/15 19:22:16 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	syntax_error_meta(t_args *args)
{
	t_pars_node	*i;

	i = args->parser->head;
	while (i && i->next)
	{
		if (check_enum(i->type) && check_enum(i->next->type))
		{
			print_syntax_error(ERR_TOKEN, i->next->content);
			g_exit_status = 2;
			return (-1);
		}
		i = i->next;
	}
	// node = args->parser->head;
	// if (!ft_strcmp(node->content, "||"))
	// 	print_syntax_error(ERR_TOKEN, "||");
	// else if (!ft_strcmp(node->content, "|"))
	// 	print_syntax_error(ERR_TOKEN, "|");
	return (1);
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
		if (i->previous && i->previous->type == CMD)
			cmd = 1;
		if (i->type >= SIMPLE_ARG && i->type < OPTION)
			cmd = 0;
		if (i->previous && (i->previous->type == CMD \
		|| i->previous->type == OPTION) && i->content[0] == '-' \
			&& i->content[1] != 0)
			i->type = OPTION;
		if (i->type != OPTION && cmd == 1)
			i->type = SIMPLE_ARG;
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
	split_meta(args->parser);
	split_meta(args->parser);
	// syntax error near unexpected token `<' trouver les token qui failent
	//  < > << >> ; | 
	// printf("args->next = %p", args->parser->tail);
	logical_attribution(args->parser);
//	split_expand(args->parser, args->env);
	cmd_attribution(args->parser);

	t_pars_node *node;
	node = args->parser->head;
	while (node)
	{
		printf("TYPE : %d\n", node->type);
		node = node->next;	
	}
	// ajouter fonction d'erreur token rate 
	if (syntax_error_meta(args) < -1 || forbidden_token(args->parser))
		return (-1);
	return (0);
}
