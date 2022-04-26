/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 19:43:25 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/26 21:52:24 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_cmds(t_pars_list *l)
{
	t_pars_node	*node;
	int			cmds;

	cmds = 0;
	node = l->head;
	if (!l || !node)
		return (-1);
	while (node)
	{
		if (node->type == CMD)
			cmds++;
		node = node->next;
	}
	printf("nb cmds = %d\n", cmds);
	return (cmds);
}

int	count_options(t_pars_node *cpy)
{
	int			i;
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
	printf("nb option = %d\n", i);
	return (i);
}

int	*create_and_fill_options(t_pars_list *l, int size)
{
	int			*options;
	t_pars_node	*node;
	int			index;

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
	t_pars_node	*i;
	int			count;
	char		**cmds;

	cmds = NULL;
	cmds = malloc(sizeof(char *) * (limit + 1));
	printf("YO limit = %d\n", limit);
	if (!cmds)
	{
		printf("YO 2\n");
		return (NULL);
	}
	cmds[0] = ft_strdup(cpy->content_exp_sans_q);
	count = 1;
	i = cpy->next;
	while (i && count < limit)
	{
		if (i->type == OPTION)
		{
			printf("i->content = %s\n", i->content);	
			cmds[count] = ft_strdup(i->content_exp_sans_q);
		}
		if (!cmds[count])
			malloc_failed(cmds, count);
		count++;
		i = i->next;
	}
	i = cpy->next;
	while (i && count < limit)
	{
		if (i->type == SIMPLE_ARG)
			cmds[count] = ft_strdup(i->content_exp_sans_q);
		if (!cmds[count])
			malloc_failed(cmds, count);
		count++;
		i = i->next;
	}
	cmds[count] = NULL;
	int n = -1;
	while (cmds[++n])
		printf("cmds = %s\n", cmds[n]);
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
	free(options);
	return (0);
}
