/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:43:25 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/14 22:09:58 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/minishell.h"

int count_cmds(t_pars_list *l)
{
    t_pars_node *node;
    int         cmds;

    cmds = 0;
    node = l->head;
    while (node)
    {
        if (node->type == CMD)
            cmds++;
        node = node->next;
    }
    return (cmds);
}

int	count_options(t_pars_node *cpy)
{
	t_pars_node	*node;
	int i;

	i = 1;
	if (!cpy->next)
		return (i);
	node = cpy->next;
	while (node && (node->type == OPTION || node->type == SIMPLE_ARG))
	{
		i++;
		node = node->next;
	}
	return (i);
}

int *create_and_fill_options(t_pars_list *l, int size)
{
    int         *options;
    t_pars_node *node;
    int 		index;

	index = 0;
    node = l->head;
    options = malloc(sizeof(int) * size);
    if (!options)
        return (NULL);
    while (node)
    {
        if (node->type == CMD)
		{
			options[index] = count_options(node);
			index++;
		}
		node = node->next;
    }
	return (options);
}

char	**create_options_tab(t_pars_node *cpy, int limit)
{
	t_pars_node *i;
	int			count;
	char		**cmds;

	cmds = malloc(sizeof(char *) * (limit + 1));
	if (!cmds)
		return (NULL);
	count = 0;
	cmds[count++] = ft_strdup(cpy->content);
	i = cpy->next;
	while (i && count < limit)
	{
		cmds[count] = ft_strdup(i->content);
		if (!cmds[count])
			malloc_failed(cmds, count);
		count++;
		i = i->next;
	}
	cmds[count] = NULL;
	return (cmds);
}

int	options_maestro(t_args *args, t_pars_list *l)
{
	int			*options;
	int			index;
	t_pars_node	*i;

	(void)args;
	options = create_and_fill_options(l, count_cmds(l));
	if (!options)
		return (-1);
	index = 0;
	i = l->head;
	while (i)
	{
		if (i->type == CMD)
		{
			i->cmds = create_options_tab(i, options[index]);
			if (!i->cmds)
				return (-1);
			index++;
		}
		i = i->next;
	}
	return (0);
}
