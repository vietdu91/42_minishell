/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bultin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:45:37 by emtran            #+#    #+#             */
/*   Updated: 2022/01/21 14:53:10 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULTIN_H
# define BULTIN_H

/*		ENV.C		*/

t_env_list	*init_env_list(void);
void		get_env(t_args *args, char **envp);

/*		CD.C		*/

void		cd_main(char *path);

/*		EXIT.C		*/

void		exit_main(t_args *args);

/*		PWD.C		*/

int			pwd_main(void);

#endif
