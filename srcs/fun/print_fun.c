/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyoula <dyoula@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:50:25 by emtran            #+#    #+#             */
/*   Updated: 2022/05/17 20:25:01 by dyoula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_demon(void)
{
	ft_putstr("\n\n\033[5;91m", 1);
	ft_putstr("          (                      )\n", 1);
	ft_putstr("          |\\    _,--------._    / |\n", 1);
	ft_putstr("          | `.,'            `. /  |\n", 1);
	ft_putstr("          `  '              ,-'   '\n", 1);
	ft_putstr("           \\/_         _   (     /\n", 1);
	ft_putstr("          (,-.`.    ,',-.`. `__,'\n", 1);
	ft_putstr("           |/#\\ ),-','#\\`= ,'.` |\n", 1);
	ft_putstr("           `._/)  -'.\\_,'   ) ))|\n", 1);
	ft_putstr("           /  (_.)\\     .   -'//\n", 1);
	ft_putstr("          (  /\\____/\\    ) )`'\\\n", 1);
	ft_putstr("           \\ |V----V||  ' ,    \\\n", 1);
	ft_putstr("            |`- -- -'   ,'   \\  \\      _____\n", 1);
	ft_putstr("     ___    |         .'    \\ \\  `._,-'     `-\n", 1);
	ft_putstr("        `.__,`---^---'       \\ ` -'\n", 1);
	ft_putstr("           -.______  \\ . /  ______,-\n", 1);
	ft_putstr("                   `.     ,'            \e[0m\n\n\n", 1);
	ft_putstr("🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n\n", 1);
}

void	print_scare_me(void)
{
	ft_putstr(" .-.\n", 1);
	ft_putstr("(o o) boo!\n", 1);
	ft_putstr("| O \\\n", 1);
	ft_putstr(" \\   \\\n", 1);
	ft_putstr("  `~~~'\n", 1);
}
