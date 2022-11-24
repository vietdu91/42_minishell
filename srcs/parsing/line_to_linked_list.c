/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_linked_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:53:43 by dyoula            #+#    #+#             */
/*   Updated: 2022/01/20 16:08:56 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* FIRST WORD

** STRJOIN AVEC BUF[1] TANT QU'ON A PAS D'ESPACE**
** LE MOT VA DEVENIR LE CONTENT DU DERNIER MAILLON DE LA LISTE **
**			=> CHECKER SI C'EST UNE CMD OU BUILTIN ETC **


TOUT CE QUI EST APRES UNE COMMANDE ET QUI N'EST PAS UN FLAG EST UN ARGUMENT */