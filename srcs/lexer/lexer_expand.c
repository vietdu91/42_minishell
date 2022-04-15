/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:03:17 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/15 20:04:51 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	content_is_to_split(char *content)
{

	int	quote;
	int	i;

	i = 0;
	quote = 0;
	while (str[i] != '\'' && str[i] != '\"')
		i++;
	while (str[i])
	{
		if (str[i] == '\'' && quote == 0)
			quote = str[i];
		if (str[i] == '"' && quote == 0)
			quote = str[i];
		if (str[i] == quote && quote != 0)
			return (1);
	}
	return (0);
	
	if (is_quote(*content) == 1)
	{
		while (*content != '\'')
			(*content)++;
	}
	else if (is_quote(*content) == 2)
	{
		while (*content != '"')
			(*content)++;
	}
	else (*content == '$')
		// faire le truc pour spliter
	else
		
}

int return_var(char **str, t_env_list *env)
{
    int     i;
	char	*var;
	char	*content;

    i = 0;
    /*LOL="      hibou   bubble    tea"
    cat $LOL"$LOL"
    ===>
    cat : hibou
    cat : bubble
    cat : tea
    cat : '      hibou   bubble    tea'
    ======
    On checke caractere par caractere
    Si une variable en $ existe, sans qu'il soit entre quotes
    On reutilise les fonctions d'expand, en checkant la variable, et en
    cherchant son contenu, et on split son contenu.
    Et après on continue le check du str pour voir si on peut toujours spliter
    le contenu des prochaines variables ou non */

	var = ft_strdup("");
	content = ft_strdup("");
	// printf("line : %s\n", line);
	while (*str)
	{
		if (*str && *str == '$')
		{
			i++;
			var = check_variable(str, ft_strlen(str));
			// printf("VAR : %s\n", var);
			content = put_content_trim_of_expand(var, env);
			// printf("CONTENT : %s\n", content);
			free(var);
		}
		(str)++;
	}
	return (i);
}

int loop_var(char *str, t_env_list *env, t_pars_node *node)
{
    while(*str)
	
		// on va return le content du var
		return_var(&str, env);
		
		// je guette si elle est a split 

		// if split creer nouveaux nodes a la suit 
		// else content exp
	}
}

int split_expand(t_pars_list *l, t_env_list *env)
{
    t_pars_node *node;
    int         i;

    node = l->head;
    while (node)
    {
		// veiller a ce que ce ne soit pas entre quotes 
        return_var(node->content, env);
        node = node->next;
    }
    
    
}