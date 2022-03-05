/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:17:41 by dyoula            #+#    #+#             */
/*   Updated: 2022/03/05 16:29:58 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_slash(char **to_try)
{
	int	i;
	int	end;

	i = -1;
	while (to_try[++i])
	{
		end = ft_strlen(to_try[i]);
		if (to_try[i][end - 1] != '/')
			to_try[i] = ft_strjoin(to_try[i], "/");
	}
}

int	add_cmd(char **to_try, char *cmd)
{
	int		i;
	char	**av;

	av = ft_split(cmd, ' ');
	if (!av)
		return (0);
	i = -1;
	while (to_try[++i])
	{
		to_try[i] = ft_strjoin(to_try[i], av[0]);
		if (!to_try[i])
			return (0);
	}
	free_d_tab(av);
	return (1);
}

char	**check_errors(char *array, char *cmd)
{
	char	**to_try;

	to_try = ft_split(array, ':');
	if (!to_try)
		return (NULL);
	if (array[0] != '/')
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
	t_pars_node	*node;

	node = args->parser->head;
	line_with_path = find_path(args->env_tab);
	while (node)
	{
		if (node->type == CMD)
		{
			to_try = check_errors(line_with_path, node->cmds[0]);
			node->path = ft_strdup(return_path(to_try));
			free(to_try);
			to_try = NULL;
			if (!node->path)
				return (-1);
		}
		node = node->next;
	}
	return (0);
}
