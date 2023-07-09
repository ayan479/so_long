/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathpath.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:35:39 by mayan             #+#    #+#             */
/*   Updated: 2023/07/08 19:49:40 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	check_map_size(t_data *game)
// {
// 	int	i;

// 	i = 0;
// 	while (game->map[0][i] != '\0')
// 		i++;
// 	game->size_x = i;
// 	i = 0;
// 	while (game->map[i] != NULL)
// 		i++;
// 	game->size_y = i;
// }

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
	ft_printf("\e[31m\e[1mJoe13\n");
	if (game->vpath[y][x] == 1)
	{
		ft_printf("\e[31m\e[1mJoe133\n");
		return (1);
	}
	if (game->map[y][x] == '1')
	{
		return (1);
	}
	ft_printf("\e[31m\e[1mJoe13333\n");
	return (0);
}

void	dfs(t_data *game, int x, int y)
{
	game->vpath[y][x] = 1;
	ft_printf("\e[31m\e[1mJoe11\n");
	if (game->map[y][x] == 'C')
		game->validcoin++;
	if (game->map[y][x] == 'E')
		game->validexit++;
	ft_printf("\e[31m\e[1mJoe12\n");
	if (pathcheck(game, x, y - 1) == 0)
		dfs(game, x, y - 1);
	if (pathcheck(game, x + 1, y) == 0)
		dfs(game, x + 1, y);
	if (pathcheck(game, x, y + 1) == 0)
		dfs(game, x, y + 1);
	if (pathcheck(game, x - 1, y) == 0)
		dfs(game, x - 1, y);
}

void	validpath(t_data *game)
{
	// check_map_size(game);
	find_coordinates(game);
	ft_printf("\e[31m\e[1mJoe1\n");
	dfs(game, game->px, game->py);
	ft_printf("\e[31m\e[1mJoe2\n");
	if (game->validcoin != game->coins || game->validexit != 1)
	{
		ft_printf("\e[31m\e[1mError: Invalid Path to Exit/Collectables \n\n");
		exitpoint(game);
	}
}
