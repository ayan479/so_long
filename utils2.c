/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:09:54 by mayan             #+#    #+#             */
/*   Updated: 2023/07/09 21:40:04 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freearray(char **p)
{
	int	i;

	i = 0;
	while (p != NULL && p[i])
	{
		free(p[i]);
		i++;
	}
	if (p)
	{
		free(p);
		p = NULL;
	}
}

void	hashmaker(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			game->vpath[y][x] = 0;
			x++;
		}
		y++;
	}
}

int	exitpoint(t_data *game)
{
	int	line;

	line = 0;
	while (game->height > line)
		free(game->map[line++]);
	free(game->map);
	exit(0);
}

void	closewin(t_data *game)
{
	mlx_clear_window(game->mlxptr, game->winptr);
	mlx_destroy_window(game->mlxptr, game->winptr);
	exit(0);
}

int	mouse(t_data *game)
{
	closewin(game);
	return (0);
}
