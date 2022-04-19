/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:55:56 by emtran            #+#    #+#             */
/*   Updated: 2022/04/19 18:19:18 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

/*		FREE_BOX.C		*/

void		free_all(t_args *args);
void		free_d_tab(char **tb);
void		free_builtins(t_builtin *builtin);
char		**free_split(char **split, int index);

/*		FREE_LISTS.C		*/

void		free_pars_list(t_pars_list *l);
void		free_env_node(t_env	*node);
void	    delete_pars_node(t_pars_node *node);
void		free_content_env_node(t_env *node);
void		free_env_list(t_env_list *env);

/*		INIT_PARSING_LIST.C			*/

int			init_parsing_list(t_pars_list **l);
void		init_parsing_node(t_pars_node *node);
t_pars_list	*list_end_parse(t_pars_list *list, char *content);
t_pars_list	*list_mid_parse(t_pars_list *list, t_pars_node *n, char *content);
void		display_parsing(t_pars_list *l);

/*		INITIALISATION.C		*/

void		init_and_set_all(t_args *args, char **envp);
void		init_struct(t_args *args);
void		set_all(t_args *args, char **envp);

/*		INITIALISATION_ENV.C	*/

t_env_list	*init_env_list(t_env_list *env, t_args *args);
void		init_env_node(t_env *node);
void		reset_env_node(t_env *node);

/*		INITIALISATION_NO_ENV.C		*/

void		get_env_if_no_env(t_args *args);

#endif