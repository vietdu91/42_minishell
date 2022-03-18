/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:17:41 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/18 14:39:31 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**check_errors(char *array, char *cmd)
{
	char	**to_try;
	
	to_try = ft_split(array, ':');
	if (!to_try)
		return (NULL);
	add_slash(to_try);
	if (!add_cmd(to_try, cmd))
		return (NULL);
	return (to_try);
}

char *return_path(char **to_try)
{
	int	i;

	i = -1;
	while (to_try[++i])
		if (!access(to_try[i], F_OK))
			return (to_try[i]);
	return (NULL);
}

int path_maestro(t_args *args)
{
	char		**to_try;
	char		*line_with_path;
	char		*path;
	t_pars_node	*node;

	to_try = NULL;
	node = args->parser->head;
	line_with_path = find_path(args->env_tab);
	while (node)
	{
		if (node->type == CMD)
		{
			to_try = check_errors(line_with_path, node->cmds[0]);
			if (!cmd_is_path(node->content, node))
			{
				path = return_path(to_try);
				if (path == NULL)
				{
					node->path = NULL;
					print_error(BASH, NULL, node->content_exp_sans_q, ERR_CMD);
					g_exit_status = 127;
				}
				else
					node->path = ft_strdup(path);
			}
			free(to_try);
			to_try = NULL;
		}
		node = node->next;
	}
	return (0);
}
