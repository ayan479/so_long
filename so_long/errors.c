/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:45:40 by mayan             #+#    #+#             */
/*   Updated: 2023/07/01 16:41:26 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkwalls(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		if (game->map[y][0] != '1' || game->map[y][game->width] != '1')
		{
			printf("\e[31m\e[1mError:\nNO WALLS on Y axis\n");
			return (0);
		}
		y++;
	}
	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1' || game->map[y - 1][x] != '1')
		{
			printf("\e[31m\e[1mError:\nNO WALL on X axis\n");
			return (0);
		}
		x++;
	}
	return (1);
}

void	mapshape(t_data	*game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y] && y < game->height)
	{
		x = 0;
		while (game->map[y][x])
			x++;
		if (x != game->width)
		{
			printf("\e[31m\e[1mError:\nMap Irregular shape/not rectangle\n");
			exit(1);
		}
		y++;
	}
}

void	errorcheck(t_data *game)
{
	checkwalls(game);
	mapshape(game);

}
