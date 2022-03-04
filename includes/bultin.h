/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2022/03/04 16:08:19 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTIN_H
# define BULTIN_H

/*		CD.C		*/

void		cd_main(char *path, t_args *args);

/*		ECHO.C		*/

int			check_option(char *str);
void		echo_main(t_args *args, t_pars_node *parser);

/*		ENV.C		*/

void		display_env(t_pars_node *node, t_env_list *env);
void		get_env(t_args *args, char **envp);

/*				ENV_CHANGE.C	*/

t_env_list	*add_var_to_env(t_env_list *env, char *content, t_args *args);
void		export_var_to_export(t_args *args, t_env_list *export, char *var, \
int check);
void		export_var_to_env(t_args *args, t_env_list *env, char *var, \
int check);

/*				ENV_SET.C	*/

void		set_new_content_in_env(t_env *node, char *content, t_args *args);
void		set_new_content_in_export(t_env *node, char *content, t_args *args, \
int check);
char		*set_variable_env(char *str);
char		*set_content_env(char *str);
int			set_id_env(char *str);

/*		EXIT.C		*/

void		error_numeric_exit(t_args *args, char *content);
int			check_len_llu_nb(char *content);
void		say_hello_wave_goodbye(t_args *args, char *content, int neg, \
unsigned long long exit_status);
void		exit_main(t_args *args, t_pars_node *parser);

/*		EXPORT.C		*/

void		get_export(t_args *args);
int			check_id_export(char *str);
void		export_main(t_args *args, t_env_list *env, t_env_list *export, \
t_pars_node *parser);

/*				EXPORT_CHANGE.C		*/

int			check_existing_var(t_env_list *env, char *var);
void		replace_existing_var(t_args *args, t_env_list *env, char *var);
void		replace_existing_var_exp(t_args *args, t_env_list *export, \
char *var, int check);

/*				EXPORT_TAB.C		*/

void		display_export(t_env_list *export);
void		set_node_export(t_env *node, t_env *env, t_args *args);
t_env_list	*set_var_to_export(t_env_list *export, t_env *env, t_args *args);
void		swap_export(t_env *node, t_env *node2);
void		sort_export(t_env_list *export);

/*		PWD.C		*/

void		pwd_main(t_pars_node *parser, t_args *args);

/*				PWD_CHANGE.C		*/

void		change_pwd_env(char *newpwd, t_args *args);
void		change_oldpwd_env(char *newpwd, t_args *args);
void		change_pwd_export(char *newpwd, t_args *args);
void		change_oldpwd_export(char *newpwd, t_args *args);

/*		UNSET.C		*/

t_env		*find_previous_node(t_env_list *env, char *var);
void		delete_var_list(t_env_list *env, char *var);
int			check_id_unset(char *str);
void		unset_main(t_args *args, t_pars_node *parser);

#endif
