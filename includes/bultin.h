/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2022/03/25 01:54:03 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTIN_H
# define BULTIN_H

/*		CD.C		*/

void		find_cd(t_args *args, t_env_list *env, unsigned char *oldpwd, unsigned char *path);
void		cd_main(t_args *args, t_env_list *env, t_pars_node *parser);

/*			CD_SPECIAL.C	*/

void		error_because_lost_dir(unsigned char *oldpwd, unsigned char *command);
void		cd_moins(t_args *args, t_env_list *env, unsigned char *oldpwd);
void		cd_home(t_args *args, t_env_list *env, unsigned char *oldpwd);

/*		ECHO.C		*/

int			check_option(unsigned char *str);
void		echo_main(t_args *args, t_pars_node *parser);

/*		ENV.C		*/

void		display_env(t_pars_node *node, t_env_list *env);
void		get_env(t_args *args, unsigned char **envp);
unsigned char		*find_content_in_env(unsigned char *var, t_env_list *env);

/*				ENV_CHANGE.C	*/

t_env_list	*add_var_to_env(t_env_list *env, unsigned char *content, t_args *args);
void		export_var_to_export(t_args *args, t_env_list *export, unsigned char *var, \
int check);
void		export_var_to_env(t_args *args, t_env_list *env, unsigned char *var, \
int check);

/*				ENV_SET.C	*/

void		set_new_content_in_env(t_env *node, unsigned char *content, t_args *args);
unsigned char		*set_content_trim_env(unsigned char *str, unsigned char trim);
unsigned char		*set_variable_env(unsigned char *str);
unsigned char		*set_content_env(unsigned char *str);
int			set_id_env(unsigned char *str);

/*		EXIT.C		*/

void		error_numeric_exit(t_args *args, unsigned char *content);
int			check_len_llu_nb(unsigned char *content);
void		say_hello_wave_goodbye(t_args *args, unsigned char *content, int neg, \
unsigned long long exit_status);
void		exit_main(t_args *args, t_pars_node *parser);

/*		EXPORT.C		*/

void		get_export(t_args *args);
int			check_id_export(unsigned char *str);
void		export_main(t_args *args, t_env_list *env, t_env_list *export, \
t_pars_node *parser);

/*				EXPORT_CHANGE.C		*/

int			check_existing_var(t_env_list *env, unsigned char *var);
void		set_new_content_in_export(t_env *node, unsigned char *content, t_args *args, \
int check);
void		replace_existing_var(t_args *args, t_env_list *env, unsigned char *var);
void		replace_existing_var_exp(t_args *args, t_env_list *export, \
unsigned char *var, int check);

/*				EXPORT_TAB.C		*/

void		display_export(t_env_list *export);
void		set_node_export(t_env *node, t_env *env, t_args *args);
t_env_list	*set_var_to_export(t_env_list *export, t_env *env, t_args *args);
void		swap_export(t_env *node, t_env *node2);
void		sort_export(t_env_list *export);

/*				EXPORT_TRIM.C		*/

int			check_len_interior_spaces(unsigned char *str);
unsigned char		*remove_interior_spaces(unsigned char *str);
unsigned char		*check_put_content_trim_of_expand(unsigned char *var, unsigned char *content, \
t_env *node);
unsigned char		*put_content_trim_of_expand(unsigned char *var, t_env_list *env);
void		strjoin_content_trim_exp(unsigned char **str, int len, t_pars_node *psr, \
t_env_list *env);


/*		PWD.C		*/

void		pwd_main(t_pars_node *parser, t_args *args);

/*				PWD_CHANGE.C		*/
	
void		update_env(unsigned char *pwd, unsigned char *oldpwd, t_args *args);
void		change_pwd_env(unsigned char *newpwd, t_env_list *env);
void		change_oldpwd_env(unsigned char *newpwd, t_env_list *env);
void		change_pwd_export(unsigned char *newpwd, t_env_list *export);
void		change_oldpwd_export(unsigned char *newpwd, t_env_list *export);

/*		UNSET.C		*/

t_env		*find_previous_node(t_env_list *env, unsigned char *var);
void		delete_var_list(t_env_list *env, unsigned char *var);
int			check_id_unset(unsigned char *str);
void		unset_main(t_args *args, t_pars_node *parser);

#endif
