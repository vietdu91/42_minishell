/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:55:56 by emtran            #+#    #+#             */
/*   Updated: 2022/01/25 14:06:32 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

/*		FREE_BOX.C		*/

void		free_all(t_args *args);
void		free_d_tab(char **tb);
void		free_builtins(t_builtin *builtin);
void		free_env_list(t_env_list *env);
void		free_t_lists(t_list *c);

/*		INITIALISATION.C		*/

void		init_and_set_all(t_args *args, char **envp);
void		init_struct(t_args *args);
void		set_all(t_args *args, char **envp);

/*		INITIALISATION_ENV.C	*/

t_env_list	*init_env_list(t_env_list *env, t_args *args);
void		init_env_node(t_env *node);
char		*set_variable_env(char *str);
char		*set_content_env(char *str);
int			set_id_env(char *str);

/*		INITIALISATION_NO_ENV.C		*/

void		get_env_if_no_env(t_args *args);

#endif