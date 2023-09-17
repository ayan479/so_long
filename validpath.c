/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:28:36 by mayan             #+#    #+#             */
/*   Updated: 2023/09/17 21:00:45 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_coordinates(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->px = x;
				game->py = y;
			}
			else if (game->map[y][x] == 'E')
			{
				game->ex = x;
				game->ey = y;
			}
			x++;
		}
		y++;
	}
}

int	pathcheck(t_data *game, int x, int y)
{
	if (game->vpath[y][x] == 1)
	{
		return (1);
	}
	if (game->map[y][x] == '1')
	{
		return (1);
	}
	return (0);
}

void	dfs(t_data *game, int x, int y)
{
	game->vpath[y][x] = 1;
	if (game->map[y][x] == 'C')
		game->validcoin++;
	if (game->map[y][x] == 'E')
		game->validexit++;
	if (pathcheck(game, x, y - 1) == 0)
		dfs(game, x, y - 1);
	if (pathcheck(game, x + 1, y) == 0)
		dfs(game, x + 1, y);
	if (pathcheck(game, x, y + 1) == 0)
		dfs(game, x, y + 1);
	if (pathcheck(game, x - 1, y) == 0)
		dfs(game, x - 1, y);
}

void	vpathinit(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	game->vpath = malloc(sizeof(int **) * game->height);
	while (y < game->height)
	{
		game->vpath[y] = malloc(sizeof(int *) * game->width);
		x = 0;
		while (x < game->width)
		{
			game->vpath[y][x] = 0;
			x++;
		}
		y++;
	}
}

void	validpath(t_data *game)
{
	find_coordinates(game);
	dfs(game, game->px, game->py);
	if (game->validcoin != game->coins || game->validexit != 1)
	{
		ft_printf("\e[31m\e[1mError: Invalid Path to Exit/Collectables \n\n");
		exitpoint(game);
	}
}
