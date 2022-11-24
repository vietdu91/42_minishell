/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_patience.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emtran <emtran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:48:16 by emtran            #+#    #+#             */
/*   Updated: 2022/03/01 15:31:47 by emtran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_sky(t_args *args)
{
	printf("\n        `'::.\n");
	if (args->patience > 12)
		printf("    _________H ,%%%%&%%%%,            _\n");
	else
		printf("    _________H ,%%%%&%%%%,\n");
	if (args->patience > 12)
		printf("   /\\     _   \\%%&&%%%%&%%          _(_)_\n");
	else if (args->patience > 11)
		printf("   /\\     _   \\%%&&%%%%&%%           _\n");
	else
		printf("   /\\     _   \\%%&&%%%%&%%\n");
	if (args->patience > 12)
		printf("  /  \\___/^\\___\\%%&%%%%&&         (_)@(_)\n");
	else if (args->patience > 10)
		printf("  /  \\___/^\\___\\%%&%%%%&&          (@)\n");
	else if (args->patience > 9)
		printf("  /  \\___/^\\___\\%%&%%%%&&           @\n");
	else if (args->patience > 8)
		printf("  /  \\___/^\\___\\%%&%%%%&&           Y\n");
	else
		printf("  /  \\___/^\\___\\%%&%%%%&&\n");
}

void	print_prairie(t_args *args)
{
	if (args->patience > 12)
		printf("  |  | []   [] |%%\\Y&%%'          /(_)\n");
	else if (args->patience > 7)
		printf("  |  | []   [] |%%\\Y&%%'          /\n");
	else if (args->patience > 2)
		printf("  |  | []   [] |%%\\Y&%%'          |\n");
	else
		printf("  |  | []   [] |%%\\Y&%%'\n");
	if (args->patience > 4)
		printf("  |  |   .-.   | ||            \\|/\n");
	else if (args->patience > 1)
		printf("  |  |   .-.   | ||             |\n");
	else
		printf("  |  |   .-.   | ||  \n");
	if (args->patience > 6)
		printf("~~@._|@@_|||_@@|~||~~~~~~~~~~~~\\|///~~\n");
	else if (args->patience > 5)
		printf("~~@._|@@_|||_@@|~||~~~~~~~~~~~~\\|//~~~\n");
	else if (args->patience > 3)
		printf("~~@._|@@_|||_@@|~||~~~~~~~~~~~~\\|/~~~~\n");
	else if (args->patience > 0)
		printf("~~@._|@@_|||_@@|~||~~~~~~~~~~~~~|~~~~~\n");
	else
		printf("~~@._|@@_|||_@@|~||~~~~~~~~~~~~~~~~~~~\n");
}

void	you_re_beautiful(t_args *args)
{
	printf("        `"""") )""""`\n");
	if (args->patience > 13)
	{
		printf("  _                  o             ,");
		printf(" __                         _          _  \n");
		printf(" (_|   |             /            /|/  \\       ");
		printf("             o  | |        | | \n");
		printf("   |   |  __           ,_    _     | __/ _   __,");
		printf("        _|_    | |        | | \n");
		printf("   |   | /  \\_|   |   /  |  |/     |   \\|/  /  |");
		printf("  |   |  |  |  |/  |   |  |/  \n");
		printf("    \\_/|/\\__/  \\_/|_/    |_/|__/   |(__/|__/\\_/|");
		printf("_/ \\_/|_/|_/|_/|__/ \\_/|_/|__/\n");
		printf("      /|                                        ");
		printf("               |\\             \n");
		printf("      \\|                                        ");
		printf("               |/             \n");
	}
	else
		printf("\n\n");
	if (args->patience > 13)
		args->patience = 0;
}

void	print_patience(t_args *args)
{
	print_sky(args);
	print_prairie(args);
	you_re_beautiful(args);
	args->patience++;
}
