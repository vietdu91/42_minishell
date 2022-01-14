/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:55:56 by emtran            #+#    #+#             */
/*   Updated: 2022/01/14 17:09:41 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

/*		FREE_BOX.C		*/

void	free_all(t_args *args);
void	free_d_tab(char **tb);
void	free_t_lists(t_list *c);

/*		INITIALISATION.C		*/

void	init_and_set_all(t_args *args, char **envp);
void	init_struct(t_args *args);
void	set_all(t_args *args, char **envp);

#endif