/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:04:58 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 01:59:34 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_len_interior_spaces(unsigned char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] && !is_space(str[i]))
		{
			i++;
			len++;
		}
		if (str[i] && is_space(str[i]))
		{
			i++;
			len++;
		}
		while (str[i] && is_space(str[i]))
			i++;
	}
	return (len);
}

unsigned char	*remove_interior_spaces(unsigned char *str)
{
	unsigned char	*nstr;
	int		len;
	int		i;
	int		j;

	nstr = NULL;
	i = 0;
	j = 0;
	len = check_len_interior_spaces(str);
	nstr = (unsigned char *)malloc(sizeof(unsigned char *) * (len + 1));
	while (str[i])
	{
		while (str[i] && !is_space(str[i]))
			nstr[j++] = str[i++];
		if (str[i] && is_space(str[i]))
			nstr[j++] = str[i++];
		while (str[i] && is_space(str[i]))
			i++;
	}
	nstr[j] = '\0';
	free(str);
	return (nstr);
}

unsigned char	*check_put_content_trim_of_expand(unsigned char *var, unsigned char *content, t_env *node)
{
	if (!ft_strcmp(var, "$"))
	{
		content = ft_strdup("$");
		return (content);
	}
	else if (!ft_strcmp(var, "?"))
	{
		content = ft_itoa(g_exit_status);
		return (content);
	}
	else if (!ft_strcmp(var, node->variable))
	{
		content = ft_strdup(node->content_trim);
		return (content);
	}
	return (NULL);
}

unsigned char	*put_content_trim_of_expand(unsigned char *var, t_env_list *env)
{
	t_env	*node;
	unsigned char	*content;

	node = NULL;
	node = env->head;
	content = NULL;
	while (node)
	{
		content = check_put_content_trim_of_expand(var, content, node);
		if (content)
			return (content);
		node = node->next;
	}
	content = ft_strdup("");
	return (content);
}

void	strjoin_content_trim_exp(unsigned char **str, int len, t_pars_node *psr, \
t_env_list *env)
{
	unsigned char	*var;
	unsigned char	*content;

	var = NULL;
	content = NULL;
	var = check_variable(str, len);
	content = put_content_trim_of_expand(var, env);
	psr->content_exp = ft_strjoin(psr->content_exp, content);
	free(content);
	free(var);
}
