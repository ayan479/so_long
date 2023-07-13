/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 19:45:40 by mayan             #+#    #+#             */
/*   Updated: 2023/07/09 19:07:41 by mayan            ###   ########.fr       */
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
		if (game->map[y][0] != '1' || game->map[y][game->width - 1] != '1')
		{
			ft_printf("\e[31m\e[1mError:\nMISSING WALL!\n");
			exitpoint(game);
		}
		y++;
	}
	x = 0;
	while (game->map[0][x])
	{
		if (game->map[0][x] != '1' || game->map[y - 1][x] != '1')
		{
			ft_printf("\e[31m\e[1mError:\nMISSING WALL!\n");
			exitpoint(game);
		}
		x++;
	}
	return (1);
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

int	check_pec(t_data *game)
{
	game->players = count_characters('P', game);
	game->exits = count_characters('E', game);
	game->coins = count_characters('C', game);
	if (game->players == 1 && game->exits == 1 && game->coins > 0)
		return (1);
	else if (game->players != 1)
	{
		ft_printf("\e[31m\e[1mError:\nInvalid No. of Players\n");
		exitpoint(game);
		return (0);
	}
	else if (game->exits != 1)
	{
		ft_printf("\e[31m\e[1mError:\nInvalid No. of Exits\n");
		exitpoint(game);
		return (0);
	}
	else if (game->coins == 0)
	{
		ft_printf("\e[31m\e[1mError:\nInvalid No. of Collectables\n");
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
				check_pec(game);
			x++;
		}
		y++;
	}
	return (1);
}
