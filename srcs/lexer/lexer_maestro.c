/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_maestro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/17 16:18:25 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_first(t_args *args)
{
	t_pars_node	*node;

	node = args->parser->head;
	if (!ft_strcmp(node->content, "||"))
		print_syntax_error(ERR_TOKEN, "||");
	else if (!ft_strcmp(node->content, "|"))
		print_syntax_error(ERR_TOKEN, "|");
	return (1);
}

void	cmd_attribution(t_pars_list *l)
{
	t_pars_node	*i;
	int			cmd;

	cmd = 0;
	i = l->head;
	if (i && i->type == 0)
		i->type = CMD;
	if (i->next)
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
	if (!args->buffer)
		return (0);
	logical_attribution(args->parser);
	cmd_attribution(args->parser);
	// check_first(args);
	//check_if_meta(args->parser);
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
