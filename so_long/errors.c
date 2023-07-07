/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:45:40 by mayan             #+#    #+#             */
/*   Updated: 2023/07/07 21:48:43 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flag(int z, t_data *game)
{
	if (z == 1)
	{
		printf("\e[31m\e[1mError:\nNO WALLS on Y axis\n");
		exitpoint(game);
		return (0);
	}
	if (z == 2)
	{
		printf("\e[31m\e[1mError:\nNO WALL on X axis\n");
		exitpoint(game);
		return (0);
	}
	if (z == 3)
	{
		printf("\e[31m\e[1mError:\nNO WALL on X and Y axis\n");
		exitpoint(game);
		return (0);
	}
	else
		return (1);
}

int	checkwalls(t_data *game)
{
	int	x;
	int	y;
	int	z;

	z = 0;
	y = 0;
	while (game->map[y])
	{
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
		{
			z += 1;
		}
		y++;
	}
	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1' || game->map[y - 1][x] != '1')
		{
			z += 2;
		}
		x++;
	}
	return (flag(z, game));
}

int	mapshape(t_data *game)
{
	int	i;

	i = 0;
	while (game->map[i] && i < game->height - 1)
	{
		i++;
		if (game->width != (int)(ft_strlen(game->map[i]))
				|| ft_strlen(game->map[i]) == 0)
		{
			ft_printf("\e[31m\e[1mError:\nNot rectangular/Empty line?\n");
			exitpoint(game);
		}
	}
	return (1);
}

int	check_pec(char z, t_data *game)
{
	if (z == 'P')
		game->players++;
	else if (z == 'E')
		game->exits++;
	else if (z == 'C')
		game->coins++;

	ft_printf("Players: %d, Exits: %d, Coins: %d\n", game->players, game->exits, game->coins);

	if (game->players == 1 && game->exits == 1 && game->coins > 0)
		return (1);
	else if (game->players == 1 && game->exits == 1 && game->coins > 0)
	{
		ft_printf("\e[31m\e[1mError:\nInvalid No. of Players/Exits/Collectables\n");
		exitpoint(game);
		return (0);
	}
	return (0);
}

int	charactercheck(t_data *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '1' && game->map[y][x] != '0' &&
			game->map[y][x] != 'P' && game->map[y][x] != 'E'
			&& game->map[y][x] != 'C')
			{
				ft_printf("\e[31m\e[1mError:\nINVALID CHARACTERS\n");
				exitpoint(game);
			}
			else if (game->map[y][x] == 'P' || game->map[y][x] == 'E'
			|| game->map[y][x] == 'C')
				check_pec(game->map[y][x], game);
			x++;
		}
		y++;
	}
	return (1);
}
