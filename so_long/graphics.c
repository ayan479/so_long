/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 20:44:45 by mayan             #+#    #+#             */
/*   Updated: 2023/06/14 21:52:28 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	place_player(t_data *game, int height, int width)
// {
// 	mlx_put_image_to_window(game->mlxptr,
// 		game->winptr, game->player, width * 45, height * 40);
// 		game->p_x = x;
// 		game->p_y = y;
// }

// void	place_coin(t_data *game, int height, int width)
// {
// 	mlx_put_image_to_window(game->mlxptr,
// 		game->winptr, game->coin, width * 40, height * 40);
// 	game->coin++;
// }

void	chr2img(t_data	*game, char c, int x, int y)
{
	if (c == '1')
		drawimg(game, WALL, x, y);
	else if (c == 'P')
	{
		drawimg(game, MEW, x, y);
		game->px = x;
		game->py = y;
	}
	else if (c == 'C')
	{
		drawimg(game, COIN, x, y);
		game->coins++;
	}
	else if (c == '0')
		drawimg(game, FLOOR, x, y);
	else if (c == 'E')
		drawimg(game, EXIT, x, y);
}

void	drawimg(t_data	*game, char *path, int x, int y)
{
	int	size;

	size = 64;
	x = x * size;
	y = y * size;
	game->img = mlx_xpm_file_to_image(game->mlxptr, path, &size, &size);
	mlx_put_image_to_window(game->mlxptr, game->winptr, game->img, x, y);
	mlx_destroy_image(game->mlxptr, game->img);
}

void	drawmap(t_data	*game)
{
	int	h;
	int	w;

	h = 0;
	game->coins = 0;
	while (h < game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			ft_printf("Height: %d, Width: %d\n", h, w);
			chr2img(game, game->map[h][w], w, h);
			w++;
		}
		h++;
	}
}
