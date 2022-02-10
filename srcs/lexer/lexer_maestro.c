/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_maestro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:33:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/02/10 19:36:52 by dyoula           ###   ########.fr       */
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
			ft_putstr("syntax error near unexpected token", 2);
			ft_putstr("\' ", 2);
			ft_putstr(i->next->content, 2);
			ft_putstr("\'\n", 2);
			// print_error(NULL, args);
		}
		i = i->next;
	}
	// if (!ft_strcmp(i->content, "||"))
	// 	print_error("syntax error near unexpected token `||'", args);
	// else if (!ft_strcmp(i->content, "|"))
	// 	print_error("syntax error near unexpected token `|'", args);
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
	if (!args->parser)
		return (0);
	logical_attribution(args->parser);
	cmd_attribution(args->parser);
	if (syntax_error_meta(args))
		return (-1);
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
