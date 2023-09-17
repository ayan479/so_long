/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:11:19 by mayan             #+#    #+#             */
/*   Updated: 2023/09/16 18:58:01 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wincondition(t_data *game)
{
	if (game->coins <= 0 && game->map[game->py][game->px] == 'E')
	{
		ft_printf("\033[1m\e[32mG\e[3m\e[92mA\033[0m");
		ft_printf("\033[1m\e[32mM\e[3m\e[92mE\033[0m");
		ft_printf(" \033[1m\e[32mO\e[3m\e[92mV\033[0m");
		ft_printf("\033[1m\e[32mE\e[3m\e[92mR\033[0m");
		ft_printf("\033[1m\e[32m!\033[0m");
		ft_printf("\033[1m\e[32mY\e[3m\e[92mO\033[0m");
		ft_printf("\033[1m\e[32mU\e[3m \e[92mW\033[0m");
		ft_printf("\033[1m\e[32mI\e[3m\e[92mN\033[0m");
		closewin(game);
	}
}

void	coincollect(t_data *game, int x, int y)
{
	if (1)
		ft_printf("\e[4;3;93mMoves: %d\n\e[0m", ++game->moves);
	if (game->map[y][x] == 'C')
	{
		game->coins--;
		game->map[y][x] = '0';
	}
	game->px = x;
	game->py = y;
}

int	move(t_data *game, int y, int x)
{
	if (game->map[game->py + y][game->px + x] == '1')
		return (0);
	else if (game->coins > 0 && game->map[game->py + y][game->px + x] == 'E')
	{
		drawimg(game, FLOOR, game->px, game->py);
		drawimg(game, EXITMEW, game->px + x, game->py + y);
		ft_printf("\e[95m\e[3;1m\nCOLLECT ALL THE CANDY FIRST MEW!\n\n");
		coincollect(game, game->px + x, game->py + y);
		game->flag = 1;
	}
	else
	{
		drawimg(game, FLOOR, game->px, game->py);
		drawimg(game, MEW, game->px + x, game->py + y);
		coincollect(game, game->px + x, game->py + y);
		if (game->flag == 1 && game->map[game->py + y][game->px
			+ x] != 'E')
		{
			drawimg(game, EXIT, game->ex, game->ey);
			game->flag = 0;
		}
		wincondition(game);
	}
	return (0);
}

int	keyhooks(int keycode, t_data *game)
{
	if (keycode == W || keycode == UP)
		move(game, -1, 0);
	else if (keycode == A || keycode == RIGHT)
		move(game, 0, -1);
	else if (keycode == S || keycode == DOWN)
		move(game, 1, 0);
	else if (keycode == D || keycode == LEFT)
		move(game, 0, 1);
	else if (keycode == ESC)
	{
		ft_printf("--------------------------------------------------\n");
		ft_printf("|              You gave up :(                    |\n");
		ft_printf("--------------------------------------------------\n");
		closewin(game);
	}
	return (0);
}
