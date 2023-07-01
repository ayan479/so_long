/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:10:24 by mayan             #+#    #+#             */
/*   Updated: 2023/06/22 15:21:47 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include "utils/get_next_line.h"
# include "utils/ft_printf.h"

# define WALL "./Sprites/grass.xpm"
# define FLOOR "./Sprites/floor.xpm"
# define COIN "./Sprites/rarecandy.xpm"
# define MEW "./Sprites/mew.xpm"
# define EXIT "./Sprites/pokeball.xpm"
# define EXITMEW "./Sprites/exitmew.xpm"

typedef struct s_data
{
	int		height;
	int		width;
	int		fd;
	int		coins;
	int		px;
	int		py;
	int		ex;
	int		ey;

	char	**map;

	void	*mlxptr;
	void	*winptr;
	void	*img;
}	t_data;

int		exitpoint(t_data *game);
int		read_map(t_data *game, char **argv);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
void	drawmap(t_data *game);
void	errorcheck(t_data *game);

void	chr2img(t_data *game, char c, int x, int y);
void	drawimg(t_data *game, char *path, int x, int y);
#endif

// void 	place_images_in_game(t_data *game);
// void	adding_in_graphics(t_data *game);