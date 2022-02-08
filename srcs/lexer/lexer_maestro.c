/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_maestro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/08 17:36:58 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_first(t_args *args)
{
	t_pars_node	*node;

	node = args->parser->head;
	if (!ft_strcmp(node->content, "||"))
		print_error("syntax error near unexpected token `||'", args);
	else if (!ft_strcmp(node->content, "|"))
		print_error("syntax error near unexpected token `|'", args);
	return (1);
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

int	lexer_maestro(t_args *args)
{
/*
**	check_first() is_meta ? yes ? which one ? is it an error ?
**	is_already_path() if first isn't a meta test wether it is a path itself
**	find_path() if not find the path in env
**	access() then find if its correct command
**	logical_deduction() it has to do it simply after a command its wether a flag
**	or an arg.
**	can it be executed ?
**	then execution
*/
	check_first(args);
	logical_attribution(args->parser);
	check_if_meta(args->parser);
	// checker si il y a un '-'
	return (0);
}

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
