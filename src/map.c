/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:55:48 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/02 22:35:36 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_map_height(char *file)
{
	int		fd;
	char	*buffer;
	size_t	height;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("Error to open the map's file");
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		height++;
		free(buffer);
	}
	close(fd);
	return (height);
}

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

static int	check_map_content(t_game *game)
{
	int	i;
	int	j;
	int	player;
	int	collectibles;
	int	exit;

	player = 0;
	exit = 0;
	collectibles = 0;
	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				player++;
				game->player.position.x = j;
				game->player.position.y = i;
			}
			else if (game->map[i][j] == 'E')
				exit++;
			else if (game->map[i][j] == 'C')
				collectibles++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
		}
	}
	game->total_collectibles = collectibles;
	return (player == 1 && exit == 1 && collectibles > 0);
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

int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*buffer;

	game->map_height = get_map_height(filename);
	if (game->map_height <= 0)
		return (0);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (perror("Error to open the file"), 0);
	i = 0;
	while (i < game->map_height)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		game->map[i] = ft_strtrim(buffer, "\n");
		if (!game->map[i])
			return (perror("Allocation failed"), 0);
		free(buffer);
		i++;
	}
	game->map[i] = NULL;
	game->map_width = ft_strlen(game->map[0]);
	close(fd);
	return (check_rectangle(game->map)
		&& check_map_content(game)
		&& check_walls(game->map, game->map_height));
}
