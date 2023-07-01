/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:44:57 by mayan             #+#    #+#             */
/*   Updated: 2023/07/01 16:40:21 by mayan            ###   ########.fr       */
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

int	exitpoint(t_data *game)
{
	int	line;

	line = 0;
	if (game->winptr)
		mlx_destroy_window(game->mlxptr, game->winptr);
	free(game->mlxptr);
	while (game->height > line)
		free(game->map[line++]);
	free(game->map);
	exit(0);
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
	ft_printf("%s", "joebama1\n");
	read_map(&game, argv);
	for (int i = 0; i < game.height; i++)
	{
		ft_printf("%s", game.map[i]);
	}
	ft_printf("\nHeight: %d, Width: %d\n", game.height, game.width);
	errorcheck(&game);
	game.mlxptr = mlx_init();
	game.winptr = mlx_new_window(game.mlxptr, (game.width * 64),
			(game.height * 64), "solong");
	drawmap(&game);
	ft_printf("%s", "joebama2");
	mlx_loop(game.mlxptr);
	free(game.map);
	return (0);
}
