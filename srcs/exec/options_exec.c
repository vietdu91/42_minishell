/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:43:25 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/22 13:13:15 by dyoula           ###   ########.fr       */
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
	int i;
	t_pars_node	*node;

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
			options[index] = count_options(node); // good 
			// printf("options[%d] == %d\n", index, options[index]);
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
	{
		// printf("bug malloc create options tab \n");
		return (NULL);
	}
	cmds[0] = ft_strdup(cpy->content); // good
	count = 1;
	// printf("cmds[0] == %s\n", cmds[0]); // good 
	i = cpy->next;
	while (i && count < limit)
	{
		cmds[count] = ft_strdup(i->content);
		if (!cmds[count])
			malloc_failed(cmds, count);
		// printf("cmds[%d] == %s\n" ,count, cmds[count]); // good
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
	options = create_and_fill_options(l, count_cmds(l)); // good
	if (!options)
		return (-1);
	index = 0;
	i = l->head;
	while (i)
	{
		if (i->type == CMD)
		{
			i->cmds = create_options_tab(i, options[index]); // good 
			// printf("content = %s\n", i->content);
			// printf("cmds = %s\n", i->cmds[0]);
			if (!i->cmds)
				return (-1);
			index++;
		}
		i = i->next;
	}
	free(options);
	return (0);
}
