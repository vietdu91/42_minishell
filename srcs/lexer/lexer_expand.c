/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 18:03:17 by dyoula            #+#    #+#             */
/*   Updated: 2022/04/26 20:01:58 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

int	content_is_to_split(char *content)
{
	int	quote;
	int	i;

	i = 0;
	quote = 0;
	while (content[i] && content[i] != '\'' && content[i] != '\"')
		i++;
	while (content[i])
	{
		if (content[i] == '\'' && quote == 0)
			quote = content[i];
		if (content[i] == '"' && quote == 0)
			quote = content[i];
		if (content[i] == quote && quote != 0)
			return (1);
		i++;
	}
	return (0);
}

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

char	*return_var(char *str, t_env_list *env, int datas[2])
{
	int		i;
	char	*var;
	char	*content;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			datas[0] += i;
			var = check_variable(&str, ft_strlen(str));
			datas[0] += ft_strlen(var);
			content = put_content_of_expand(var, env);
			free(var);
			return (content);
		}
		i++;
		datas[0] += i;
	}
	return (NULL);
}

int	split_to_node(char *str, t_pars_list *list, t_pars_node *node, \
t_env_list *env)
{
	t_pars_node	*node2;
	char		**split;
	int			i;

	node2 = node;
	split = NULL;
	i = 0;
	split = ft_split(str, ' ');
	if (!split)
		return (-1);
	while (split[i])
	{
	//	printf("SPLIT %d : %s\n", i, split[i]);
		list_mid_parse(list, node2, split[i]);
		expand(node2->content, node2, env);
		convert_content_without_quotes(node2->content, node2);
		encrypting(node2->content, node2);
		node2 = node2->next;
		// printf("PREVIOUS : %s\n", node2->previous->content);
		if (i == 0)
			delete_pars_node(node2->previous);
		// node2 = list->head;
		// while (node2)
		// {
		// 	printf("CONTENT1 : %s\n", node2->content);
		// 	printf("TYPE1 : %d\n\n", node2->type);
		// 	node2 = node2->next;
		// }
		i++;
	}
	return (i - 1);
}

int	loop_var(char *str, t_pars_list *l, t_env_list *env, t_pars_node *node)
{
	int		datas[2];
	char	*var;
	char	*final;

	final = ft_strdup("");
	if (!str)
		return (-1);
	datas[0] = 0;
	datas[1] = 0;
	// printf("str = %s\n", str);
	if (!is_charset('$', str))
		return (0);
	while(str[datas[0]])
	{
		// on va return le content du var
		
		// je guette si elle est a split
		//  si elle n'a pas de quotes
		// printf("prims = %s\n", str + datas[0]);
		var = return_var(str + datas[0], env, datas);
		// printf("salut len = %d && datas[0] = %d\n", ft_strlen(str), datas[0]);
		final = ft_strjoin(final, var);
		// printf("FINAL : %s\n", final);
		if (datas[0] == ft_strlen(str))
			break ;
		// var = Content on va l'utiliser pour en faire un node.
		//printf("jo- %s\n", str + datas[0]);
		//printf("1- var = %s\n", var);
		// (void)env;
		// printf("datas[0] = %d\n", datas[0]);
		// datas[0]++;
		// printf("2 datas[0] = %d\n", datas[0]);
		//printf("%c\n", str[datas[0]]);
		// if split creer nouveaux nodes a la suit 
		// else content exp
	}
	// printf("j'ai encore rien crée\n");
	// doit return le nombre de nodes crées.
	return (split_to_node(final, l, node, env));
}

int	split_expand(t_pars_list *l, t_env_list *env)
{
	t_pars_node	*node;
	int			nodes_added;
//	int			i;

	(void)env;
 	nodes_added = 0;
 	node = l->head;
	if (!node)
		return (-1);
	// printf("node = %s\n", node->content);
 	while (node != l->tail)
	{
	    // printf("node->content = %s\n", l->tail->content);
		if (!content_is_to_split(node->content))
			nodes_added += loop_var(node->content, l, env, node);	
 		node = node->next;
	}
// //	i = -1;
// 	{
// 		// veiller a ce que ce ne soit pas entre quotes
// 		// return (0);
// 		// printf("hyde = %s\n", node->content);
// 	//	printf("NODES ADDED : %d\n", nodes_added);
// 		// while (++i < nodes_added)
// 		//  	node = node->next;
// 		printf("NODE IS : %s\n", node->content);
// 	}
	return (nodes_added);
}
