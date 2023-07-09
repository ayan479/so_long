/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:10:24 by mayan             #+#    #+#             */
/*   Updated: 2023/07/09 17:32:30 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "mlx/mlx.h"
# include "utils/ft_printf.h"
# include "utils/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL "./images/grass.xpm"
# define FLOOR "./images/floor.xpm"
# define COIN "./images/rarecandy.xpm"
# define MEW "./images/mew.xpm"
# define EXIT "./images/pokeball.xpm"
# define EXITMEW "./images/exitmew.xpm"

# define W 13
# define A 0
# define S 1
# define D 2

# define ESC 53

# define UP 126
# define DOWN 125
# define LEFT 124
# define RIGHT 123

typedef struct s_data
{
	int		height;
	int		width;
	int		fd;
	int		coins;
	int		players;
	int		exits;
	int		moves;
	int		flag;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		validexit;
	int		validcoin;
	int		size_x;
	int		size_y;

	int		vpath[256][256];
	char	**map;

	void	*mlxptr;
	void	*winptr;
	void	*img;
}			t_data;

int			exitpoint(t_data *game);
void		closewin(t_data *game);
int			mouse(t_data *game);
int			read_map(t_data *game, char **argv);
char		*ft_strrchr(const char *s, int c);
int			ft_strcmp(char *s1, char *s2);
char		**ft_split(char *s, char c);
void		*ft_memcpy(void *dst, void *src, size_t n);
void		drawmap(t_data *game);
char		*ft_substr(char *s, unsigned int start, size_t len);
void		errorcheck(t_data *game);
int			charactercheck(t_data *game);
int			count_characters(char c, t_data *game);
int			mapshape(t_data *game);
int			checkwalls(t_data *game);
void		validpath(t_data *game);
void		hashmaker(t_data *game);
int			keyhooks(int keycode, t_data *game);
void		chr2img(t_data *game, char c, int x, int y);
void		drawimg(t_data *game, char *path, int x, int y);
#endif
