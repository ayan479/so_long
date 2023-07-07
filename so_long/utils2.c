/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:09:54 by mayan             #+#    #+#             */
/*   Updated: 2023/07/07 15:45:47 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	num_words(char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if ((i == 0 || s[i - 1] == c) && s[i] != c)
			n++;
		i++;
	}
	return (n);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	if (!s)
		return (0);
	tab = (char **)malloc((num_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (0);
	while (i < num_words(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		tab[i++] = ft_substr(s, start, (end - start));
		start = end;
	}
	tab[i] = 0;
	return (tab);
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
