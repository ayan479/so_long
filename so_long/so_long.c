/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:44:57 by mayan             #+#    #+#             */
/*   Updated: 2023/07/07 19:27:50 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len--)
	{
		*p++ = (unsigned char)c;
	}
	return (b);
}

void	errorcheck(t_data *game)
{
	game->coins = 0;
	game->players = 0;
	game->exits = 0;
	game->flag = 0;
	mapshape(game);
	checkwalls(game);
	charactercheck(game);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
	{
		ft_printf("NEED 2 ARGUMENTS\n");
		return (0);
	}
	ft_memset(&game, 0, sizeof(t_data));
	read_map(&game, argv);
	errorcheck(&game);
	game.mlxptr = mlx_init();
	if (!game.mlxptr)
		return (0);
	game.winptr = mlx_new_window(game.mlxptr, (game.width * 64), (game.height
				* 64), "solong");
	drawmap(&game);
	mlx_key_hook(game.winptr, keyhooks, &game);
	mlx_hook(game.winptr, 17, 0, mouse, &game);
	mlx_loop(game.mlxptr);
	free(game.map);
	return (0);
}
	// for (int i = 0; i < game.height; i++)
	// {
	// 	ft_printf("%s\n", game.map[i]);
	// }
	// ft_printf("\nHeight: %d, Width: %d\n", game.height, game.width);
	// ft_printf("\e[31m\e[1mError:\nJoebama1?\n");