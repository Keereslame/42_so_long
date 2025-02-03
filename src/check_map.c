/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:57:03 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/03 11:12:06 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangle(char **map)
{
	int		i;
	size_t	width;

	width = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != width)
			return (0);
		i++;
	}
	return (1);
}

static int	check_value(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		game->nb_player++;
		game->player.position.x = x;
		game->player.position.y = y;
	}
	else if (c == 'E')
		game->nb_exit++;
	else if (c == 'C')
		game->nb_collectibles++;
	else if (c != '0' && c != '1')
		return (0);
	return (1);
}

static int	check_map_content(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (!check_value(game, game->map[i][j], j, i))
				return (0);
		}
	}
	return (game->nb_player == 1 && game->nb_exit == 1
		&& game->nb_collectibles > 0);
}

static int	check_walls(char **map, int height)
{
	int	i;
	int	width;

	width = ft_strlen(map[0]);
	i = 0;
	while (i < width)
	{
		if (map[0][i] != '1' || map[height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	return (check_rectangle(game->map)
		&& check_map_content(game)
		&& check_walls(game->map, game->map_height));
}
