/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_maestro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/03 17:37:34 by emtran           ###   ########.fr       */
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

// void	cmd_or_option_or_arg(t_pars_node *i, int *cmd)
// {
// 	if (i->previous && i->previous->type == CMD)
// 		*cmd = 1;
// 	//printf("cmd vaut 1 : %d\n", cmd);
// 	if (i->type >= SIMPLE_ARG && i->type < OPTION)
// 		*cmd = 0;
// 	if (i->previous && (i->previous->type == CMD \
// 	|| i->previous->type == OPTION) && i->content[0] == '-' \
// 		&& i->content[1] != 0)
// 		i->type = OPTION;
// 	//printf("cmd vaut 2 : %d\n", cmd);
// 	if (i->type != OPTION && *cmd == 1)
// 		i->type = SIMPLE_ARG;
// }

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
//	printf("cmd vaut 2 : %d\n", *cmd);
	//if (i->type >= SIMPLE_ARG && i->type < OPTION)
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
//	printf("JE SUIS %s et je suis de type %d\n", i->content, i->type);
	if (i && i->next == NULL)
		return ;
	i = i->next;
	while (i)
	{
		//printf("CMD INITIAL : %d\n",cmd);
		cmd_or_option_or_arg(i, &cmd);
		//printf("JE SUIS %s et je suis de type %d\n", i->content, i->type);
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

void	arg_attribution(t_pars_list *l)
{
	t_pars_node	*node;
	int			cmds;

	cmds = 0;
	node = l->head;
	while (node)
	{
		if (node->type != CMD && node->type != OPTION && node->type != SIMPLE_ARG)
			cmds = 0;
		if (cmds == 1 && node->type == EMPTY)
			node->type = SIMPLE_ARG;
		if (node->type == CMD || node->type == PIPE)
			cmds = 1;
		node = node->next;
	}
}

// syntax error near unexpected token `<' trouver les token qui failent
//  < > << >> ; | 
// printf("args->next = %p", args->parser->tail);

// ajouter fonction d'erreur token rate 

int	lexer_maestro(t_args *args)
{
	// t_pars_node	*node;

	if (!args->parser)
		return (0);
//	split_meta(args->parser);
//	split_meta(args->parser);
	logical_attribution(args->parser);
//	split_expand(args->parser, args->env);
	// exit(0);
	cmd_attribution(args->parser);
//	arg_attribution(args->parser); // if bug search here 
	// node = args->parser->head;
	// // while (node)
	// // {
	// // 	// printf("CONTENT : %s\n", node->content);
	// // 	// printf("TYPE : %d\n\n", node->type);
	// // 	node = node->next;
	// // }
	// if (is_a_directory(args->parser->head->content_exp_sans_q))
	// {
	// 	print_error(BASH, NULL, 
	// 	args->parser->head->content_exp_sans_q, ERR_IS_DIR);
	// 	g_exit_status = 126;
	// 	return (-1);
	// }
	if (syntax_error_meta(args) < 0 || forbidden_token(args->parser))
		return (-1);
	return (0);
}
