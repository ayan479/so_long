/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:22:21 by mayan             #+#    #+#             */
/*   Updated: 2023/06/22 15:09:53 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	width_of_map(char *string)
{
	int	width;

	width = 0;
	while (string[width] != '\0')
		width++;
	if (string[width - 1] == '\n')
		width--;
	return (width);
}

static int	addline(t_data *game, char *line)
{
	int		i;
	char	**temp;

	i = 0;
	if (!line)
		return (0);
	game->height++;
	temp = (char **)malloc(sizeof(char *) * (game->height + 1));
	temp[game->height] = NULL;
	while (game->height - 1 > i)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[i] = line;
	free(game->map);
	game->map = temp;
	return (1);
}

int	ft_checkext(char *file)
{
	char			*ext;
	char			*file_ext;

	ext = ".ber";
	file_ext = ft_strrchr((const char *)file, '.');
	if (ft_strcmp(file_ext, ext) == 0)
	{
		return (1);
	}
	return (0);
}

int	read_map(t_data *game, char **argv)
{
	char	*mapline;

	if (!ft_checkext(argv[1]))
	{
		printf("\e[31m\e[1mError:\nFile extension is not Valid\n");
		exitpoint(game);
	}
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
	{
		printf("\e[31m\e[1mError:\nFile Invalid\n");
		exitpoint(game);
	}
	while (1)
	{
		mapline = get_next_line(game->fd);
		if (!addline(game, mapline))
			break ;
	}
	close(game->fd);
	game->width = width_of_map(game->map[0]);
	return (1);
}
