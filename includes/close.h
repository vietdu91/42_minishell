/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:50:29 by dyoula            #+#    #+#             */
/*   Updated: 2022/05/10 16:22:40 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSE_H
# define CLOSE_H

int	close_loop_execution(t_pars_node *i, t_pars_list *l, int datas[5]);
int	close_loop_execution_parent(int j, t_pars_list *l, int datas[5]);
int	return_datas_zero_fail(int datas[5], t_pars_list *l);

#endif