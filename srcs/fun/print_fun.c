/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:50:25 by emtran            #+#    #+#             */
/*   Updated: 2022/02/28 19:03:10 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_demon(void)
{
	printf("\n\n\033[5;91m");
	printf("          (                      )\n");
	printf("          |\\    _,--------._    / |\n");
	printf("          | `.,'            `. /  |\n");
	printf("          `  '              ,-'   '\n");
	printf("           \\/_         _   (     /\n");
	printf("          (,-.`.    ,',-.`. `__,'\n");
	printf("           |/#\\ ),-','#\\`= ,'.` |\n");
	printf("           `._/)  -'.\\_,'   ) ))|\n");
	printf("           /  (_.)\\     .   -'//\n");
	printf("          (  /\\____/\\    ) )`'\\\n");
	printf("           \\ |V----V||  ' ,    \\\n");
	printf("            |`- -- -'   ,'   \\  \\      _____\n");
	printf("     ___    |         .'    \\ \\  `._,-'     `-\n");
	printf("        `.__,`---^---'       \\ ` -'\n");
	printf("           -.______  \\ . /  ______,-\n");
	printf("                   `.     ,'            \e[0m\n\n\n");
	printf("🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n\n");
}

void	print_scare_me(void)
{
	printf(" .-.\n");
	printf("(o o) boo!\n");
	printf("| O \\\n");
	printf(" \\   \\\n");
	printf("  `~~~'\n");
}

void	print_patience(t_args *args)
{
	printf("        `'::.\n");
	printf("    _________H ,%%%%&%%%%,\n");
	printf("   /\\     _   \\%%&&%%%%&%%\n");
	printf("  /  \\___/^\\___\\%%&%%%%&&\n");
	if (args->patience > 2)
		printf("  |  | []   [] |%%\\Y&%%'          o\n");
	else
		printf("  |  | []   [] |%%\\Y&%%'\n");
	if (args->patience > 1)
		printf("  |  |   .-.   | ||             |\n");
	else
		printf("  |  |   .-.   | ||  \n");
	if (args->patience > 0)
		printf("~~@._|@@_|||_@@|~||~~~~~~~~~~~~~|~~~~~\n");
	else
		printf("~~@._|@@_|||_@@|~||~~~~~~~~~~~~~~~~~~~\n");
	printf("        `"""") )""""`\n");
	args->patience++;
}
