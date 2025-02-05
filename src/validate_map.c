/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:27:18 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/05 14:06:41 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **original, int height)
{
	char	**copy;
	int		i;

	i = 0;
	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (perror("Error\n"), NULL);
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (perror("Error\n"), NULL);
		}
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

static void	flood_fill(t_flood *flood, int pos_x, int pos_y)
{
	if (flood->map[pos_y][pos_x] == 'E')
		flood->exit_found = 1;
	if (pos_x < 0 || pos_x > flood->width || pos_y < 0 || pos_y > flood->height
		|| flood->map[pos_y][pos_x] == '1' || flood->map[pos_y][pos_x] == 'F'
		|| flood->map[pos_y][pos_x] == 'E')
		return ;
	if (flood->map[pos_y][pos_x] == 'C')
		flood->collectibles++;
	flood->map[pos_y][pos_x] = 'F';
	flood_fill(flood, pos_x + 1, pos_y);
	flood_fill(flood, pos_x, pos_y + 1);
	flood_fill(flood, pos_x - 1, pos_y);
	flood_fill(flood, pos_x, pos_y - 1);
	print_map(flood->map);
}

static int	check_valid_path(t_game *game)
{
	t_flood	flood;
	int		tot_collectibles;
	int		valid;

	valid = 0;
	flood.exit_found = 0;
	flood.collectibles = 0;
	flood.height = game->map_height;
	flood.width = game->map_width;
	tot_collectibles = game->nb_collectibles;
	flood.map = copy_map(game->map, game->map_height);
	if (!flood.map)
		return (0);
	flood_fill(&flood, game->player.position.x, game->player.position.y);
	if ((flood.collectibles == tot_collectibles) && flood.exit_found)
		valid = 1;
	free_map(flood.map);
	return (valid);
}

int	validate_map(t_game *game, char *filename)
{
	if (!create_map(game, filename))
		return (0);
	if (!read_map(game, filename))
		return (0);
	if (!check_map(game))
		return (0);
	if (!check_valid_path(game))
		return (0);
	return (1);
}
