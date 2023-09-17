/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:44:57 by mayan             #+#    #+#             */
/*   Updated: 2023/09/17 21:25:56 by mayan            ###   ########.fr       */
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
	mapshape(game);
	checkwalls(game);
	charactercheck(game);
	vpathinit(game);
	validpath(game);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
	{
		ft_printf("\e[31m\e[1mError:\nNEED 2 ARGUMENTS\n");
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
	freearray(game.map);
	return (0);
}

// int	flag(int z, t_data *game)
// {
// 	if (z == 1)
// 	{
// 		ft_printf("\e[31m\e[1mError:\nNO WALLS on Y axis\n");
// 		exitpoint(game);
// 		return (0);
// 	}
// 	if (z == 2)
// 	{
// 		ft_printf("\e[31m\e[1mError:\nNO WALL on X axis\n");
// 		exitpoint(game);
// 		return (0);
// 	}
// 	if (z == 3)
// 	{
// 		ft_printf("\e[31m\e[1mError:\nNO WALL on X and Y axis\n");
// 		exitpoint(game);
// 		return (0);
// 	}
// 	else
// 		return (1);
// }