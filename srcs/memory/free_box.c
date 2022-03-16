/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:57:13 by emtran            #+#    #+#             */
/*   Updated: 2022/03/16 02:28:23 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**free_split(char **split, int index)
{
	while (index >= 0)
		free(split[index--]);
	free(split);
	return (NULL);
}

void	free_d_tab(char **tb)
{
	int	i;

	i = -1;
	if (!tb)
		return ;
	while (tb[++i])
	{
		if (tb[i])
			free(tb[i]);
	}
	free(tb);
	tb = NULL;
}

void	free_builtins(t_builtin *builtin)
{
	if (builtin->oldpwd)
		free(builtin->oldpwd);
	if (builtin)
		free(builtin);
}

void	free_args(t_args *args)
{
	if (args->path)
		free(args->path);
	if (args->buffer)
		free(args->buffer);
	if (args->home)
		free(args->home);
	if (args->env_tab)
		free_d_tab(args->env_tab);
	if (args->hdocs)
		free_d_tab(args->hdocs);
	if (args->delimiters)
		free_d_tab(args->delimiters);
	memset(&args, 0, sizeof(args));
}

void	free_all(t_args *args)
{
	if (!args)
		return ;
	if (args->buffer)
		free(args->buffer);
	free_builtins(args->builtin);
	free_env_list(args->env);
	free_env_list(args->export);
	if (args->parser)
		free_pars_list(args->parser);
	free_args(args);
	if (args)
		free(args);
	rl_clear_history();
	args = NULL;
}
