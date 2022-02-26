/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_maestro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/26 20:45:43 by dyoula           ###   ########.fr       */
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
			ft_putstr("syntax error near unexpected token ", 2);
			ft_putstr("`", 2);
			ft_putstr(i->next->content, 2);
			ft_putstr("\'\n", 2);
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
		if (i->previous && i->previous->type == 3)
			cmd = 1;
		if (i->type >= 6 && i->type < 20)
			cmd = 0;
		if (i->previous && (i->previous->type == CMD \
		|| i->previous->type == OPTION) && i->content[0] == '-')
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
		{
			splitter_content_meta(i, l);
		}
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
	cmd_attribution(args->parser);
	// ajouter fonction d'erreur token rate 
	if (syntax_error_meta(args) < -1 || forbidden_token(args->parser))
		return (-1);
	return (0);
}

// int	cmd_is__path(t_pars_node *n, t_args	*args)
// {
// 	char	*no_space;

// 	no_space = NULL;
// 	no_space = cut_path(n->content, no_space);
// 	if (!no_space)
// 		return (0);
// 	if (access(no_space, F_OK) == 0
// 		&& (no_space[0] == '/' || no_space[0] == '.'))
// 	{
// 		n->path = ft_strdup(n->content);
// 		free(no_space);
// 		return (1);
// 	}
// 	free(no_space);
// 	return (0);
// }

// << del cmd (option) or (meta) or (file) if (next-> != meta) file file file

/*
int	lexer_maestro(t_args *args)
{
**	check_first() is_meta ? yes ? which one ? is it an error ?
**	is_already_path() if first isn't a meta test wether it is a path itself
**	find_path() if not find the path in env
**	access() then find if its correct command
**	logical_deduction() it has to do it simply after a command its wether a flag
**	or an arg.
**	can it be executed ?
**	then execution
	if (!args->buffer)
		return (0);
	logical_attribution(args->parser);
	cmd_attribution(args->parser);
	// check_first(args);
	//check_if_meta(args->parser);
	// checker si il y a un '-'
	return (0);
}
*/

// find_option_cmd(i);

// int	find_option_cmd(t_pars_node *n)
// {
// 	t_pars_node	*i;

// 	i = n;
// 	while (i && i->next && i->next->content[0] == '-')
// 	{
// 		i->next->type = 4;
// 		i = i->next;
// 	}
// }
