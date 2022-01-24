/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2022/01/24 16:45:01 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTIN_H
# define BULTIN_H

/*		ENV.C		*/

void		set_new_content_in_env(t_env *node, char *content, t_args *args);
t_env_list	*add_var_to_env(t_env_list *env, char *content, t_args *args);
void		display_env(t_args *args);
void		get_env(t_args *args, char **envp);

/*		CD.C		*/

void		cd_main(char *path, t_args *args);

/*		EXIT.C		*/

void		exit_main(t_args *args);

/*		PWD.C		*/

void		change_pwd(char *newpwd, t_args *args);
void		change_oldpwd(char *newpwd, t_args *args);
int			pwd_main(t_args *args);


#endif
