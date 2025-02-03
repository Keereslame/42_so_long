/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:55:48 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/03 11:16:33 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (free_map(game->map), perror("Error to open the file"), 0);
	i = 0;
	while (i < game->map_height)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		game->map[i] = ft_strtrim(buffer, "\n");
		if (!(game->map[i]))
			return (free(buffer), free_map(game->map),
				perror("Allocation failed"), 0);
		free(buffer);
		i++;
	}
	game->map[i] = NULL;
	close(fd);
	return (1);
}

int	create_map(t_game *game, char *filename)
{
	int	readed;
	int	checked;

	game->map_height = get_map_height(filename);
	if (game->map_height <= 0)
		return (0);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (0);
	readed = read_map(game, filename);
	game->map_width = ft_strlen(game->map[0]);
	checked = check_map(game);
	return (readed && checked);
}
