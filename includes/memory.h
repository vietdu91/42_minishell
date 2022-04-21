/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:55:56 by emtran            #+#    #+#             */
/*   Updated: 2022/04/21 19:45:06 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

/*		FREE_BOX.C		*/

char		**free_split(char **split, int index);
void		free_d_tab(char **tb);
void		free_builtins(t_builtin *builtin);
void		free_args(t_args *args);
void		free_all(t_args *args);

/*		FREE_LISTS.C		*/

void		free_env_list(t_env_list *env);
void		delete_pars_node(t_pars_node *node);
void		free_pars_list(t_pars_list *l);

/*		FREE_NODES.C		*/

void		free_env_node(t_env	*node);
void		delete_pars_node(t_pars_node *node);
void		free_content_env_node(t_env *node);

/*		INIT_CMDS			*/

t_cmds_list	*init_list(void);

/*		INIT_PARSING_LIST.C			*/

int			init_parsing_list(t_pars_list **l);
void		init_parsing_node(t_pars_node *node);
t_pars_list	*list_end_parse(t_pars_list *list, char *content);
t_pars_list	*list_mid_parse(t_pars_list *list, t_pars_node *n, char *content);
void		display_parsing(t_pars_list *l);

/*		INIT_TAB.C				*/

char		**init_env_tab(t_env_list *l);
char		**init_parse_to_tab(t_pars_list *l);

/*		INITIALISATION_ENV.C	*/

t_env_list	*init_env_list(t_env_list *env, t_args *args);
void		init_env_node(t_env *node);
void		reset_env_node(t_env *node);

/*		INITIALISATION_NO_ENV.C		*/

void		get_env_if_no_env(t_args *args);

/*		INITIALISATION.C		*/

void		set_all(t_args *args, char **envp);
void		init_struct(t_args *args);
void		init_and_set_all(t_args *args, char **envp);


#endif