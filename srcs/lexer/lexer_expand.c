/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:03:17 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/18 04:23:43 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	content_is_to_split(char *content)
{
	int	quote;
	int	i;

	i = 0;
	quote = 0;
	// printf("hum content = %s\n", content);
	while (content[i] && content[i] != '\'' && content[i] != '\"')
		i++;
	while (content[i])
	{
		if (content[i] == '\'' && quote == 0)
		{
			quote = content[i];
			// printf("c[i] = %c\n", content[i]);
			// printf("simple\n");
		}
		if (content[i] == '"' && quote == 0)
		{
			quote = content[i];
			// printf("double\n");
		}
		if (content[i] == quote && quote != 0)
		{
			// printf("quotes here\n");
			return (1);
		}
		i++;
	}
	return (0);
	
	// if (is_quote(*content) == 1)
	// {
	// 	while (*content != '\'')
	// 		(*content)++;
	// }
	// else if (is_quote(*content) == 2)
	// {
	// 	while (*content != '"')
	// 		(*content)++;
	// }
	// else (*content == '$')
	// 	// faire le truc pour spliter
	// else
		
}

char *return_var(char *str, t_env_list *env, int datas[2])
{
	int	 	i;
	char	*var;
	char	*content;

	i = 0;
	/*LOL="	  hibou   bubble	tea"
	cat $LOL"$LOL"
	===>
	cat : hibou
	cat : bubble
	cat : tea
	cat : '	  hibou   bubble	tea'
	======
	On checke caractere par caractere
	Si une variable en $ existe, sans qu'il soit entre quotes
	On reutilise les fonctions d'expand, en checkant la variable, et en
	cherchant son contenu, et on split son contenu.
	Et après on continue le check du str pour voir si on peut toujours spliter
	le contenu des prochaines variables ou non */

	// var = ft_strdup("");
	// content = ft_strdup("");
	// printf("line : %s\n", line);
	// datas[0]++;
	// printf("addresse 2 = %p\n", datas);
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			datas[0] += i;
			var = check_variable(&str, ft_strlen(str));
			printf("VAR : %s\n", var);
			content = put_content_trim_of_expand(var, env);
			printf("CONTENT : %s\n", content);
			free(var);
			return (content);
		}
		i++;
		datas[0] += i;
	}
	return (NULL);
}

int	loop_var(char *str, t_env_list *env, t_pars_node *node)
{
	int		datas[2];
	char	*var;

	if (!str)
	{
		printf("j'ai rien reçu\n");
		return (-1);
	}
	datas[0] = 0; // index str
	datas[1] = 0; // to split ou pas;
	// printf("addresse 1= %p\n", datas);
	// printf("first datas[0] = %d\n", datas[0]);
	printf("str = %s\n", str);
	while(str[datas[0]])
	{
		// on va return le content du var
		
		// je guette si elle est a split
		//  si elle n'a pas de quotes
		printf("prims = %s\n", str + datas[0]);
		var = return_var(str + datas[0], env, datas);
		// var = Content on va l'utiliser pour en faire un node.
		(void)var;
		(void)node;
		// (void)env;
		// printf("datas[0] = %d\n", datas[0]);
		// datas[0]++;
		// printf("2 datas[0] = %d\n", datas[0]);
		printf("%c\n", str[datas[0]]);
		// if split creer nouveaux nodes a la suit 
		// else content exp
	}
	// printf("j'ai encore rien crée\n");
	// doit return le nombre de nodes crées.
	return (0);
}

int	split_expand(t_pars_list *l, t_env_list *env)
{
	t_pars_node	*node;
	int			i;
	int			nodes_added;

	nodes_added = 0;
	i = -1;
	node = l->head;
	while (node)
	{
		// veiller a ce que ce ne soit pas entre quotes
		if (!content_is_to_split(node->content))
		{
			nodes_added = loop_var(node->content, env, node);
		}
		// return (0);
		// printf("hyde = %s\n", node->content);
		while (node->next && ++i < nodes_added)
			node = node->next;
		node = node->next;
	}
	return (1);
}
