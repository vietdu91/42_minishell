/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2022/01/23 15:49:03 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTIN_H
# define BULTIN_H

/*		ENV.C		*/

t_env_list	*add_var_to_env(t_env_list *env, char *content, t_args *args);
void		display_env(t_args *args);
void		get_env(t_args *args, char **envp);

/*		CD.C		*/

void		cd_main(char *path);

/*		EXIT.C		*/

void		exit_main(t_args *args);

/*		PWD.C		*/

int			pwd_main(void);

#endif
