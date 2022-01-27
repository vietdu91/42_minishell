/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2022/01/27 14:31:55 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTIN_H
# define BULTIN_H


/*		CD.C		*/

void		cd_main(char *path, t_args *args);

/*		ENV.C		*/

void		set_new_content_in_env(t_env *node, char *content, t_args *args);
t_env_list	*add_var_to_env(t_env_list *env, char *content, t_args *args);
void		display_env(t_env_list *env);
void		get_env(t_args *args, char **envp);

/*		EXIT.C		*/

void		exit_main(t_args *args);

/*		EXPORT_UNSET.C		*/

void		get_export(t_args *args);

/*				EXPORT_TAB.C		*/

void		display_export(t_env_list *export);
void		set_node_export(t_env *node, t_env *env, t_args *args);
t_env_list	*set_var_to_export(t_env_list *export, t_env *env, t_args *args);
void		swap_export(t_env *node, t_env *node2);
void		sort_export(t_env_list *export);

/*		PWD.C		*/

int			pwd_main(t_args *args);

/*				PWD_CHANGE.C		*/

void		change_pwd_env(char *newpwd, t_args *args);
void		change_oldpwd_env(char *newpwd, t_args *args);
void		change_pwd_export(char *newpwd, t_args *args);
void		change_oldpwd_export(char *newpwd, t_args *args);

#endif
