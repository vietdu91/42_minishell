/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:17:41 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/28 11:25:01 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*	int j = -1;
	while (to_try[++j])
		printf("int path maestro to_try[%d] = %s", j, to_try[j]);*/

char	**check_errors(char *array, char *cmd)
{
	char	**to_try;

	to_try = NULL;
	to_try = ft_split(array, ':');
	if (!to_try)
		return (NULL);
	add_slash(to_try);
	if (!add_cmd(to_try, cmd))
		return (NULL);
	return (to_try);
}

char	*return_path(char **to_try)
{
	int	i;

	i = -1;
	if (!to_try)
		return (NULL);
	while (to_try[++i])
	{
		if (!access(to_try[i], F_OK))
			return (to_try[i]);
	}
	return (NULL);
}

void	if_no_cmd_is_path(char *path, char **to_try, t_pars_node *node)
{
	path = return_path(to_try);
	if (path == NULL)
	{
		node->path = NULL;
		if (is_builtin(node) && !is_special(node->content_exp_sans_q[0]))
		{
			print_error(BASH, NULL, node->content_exp_sans_q, ERR_CMD);
			g_exit_status = 127;
		}
		else if (!ft_strcmp("!", node->content_exp_sans_q))
			g_exit_status = 1;
	}
	else
		node->path = ft_strdup(path);
}

int	path_maestro(t_args *args)
{
	char		**to_try;
	char		*line_with_path;
	char		*path;
	t_pars_node	*node;

	path = NULL;
	node = args->parser->head;
	line_with_path = find_path(args->env_tab);
	to_try = NULL;
	while (node)
	{
		if (node->type == CMD)
		{
			to_try = check_errors(line_with_path, node->cmds[0]);
			if (!cmd_is_path(node->content, node))
				if_no_cmd_is_path(path, to_try, node);
			free_d_tab(to_try);
			to_try = NULL;
		}
		node = node->next;
	}
	return (0);
}
