/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:55:48 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/10 14:53:37 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_game *game, char *filename)
{
	int		fd;
	int		i;
	char	*buffer;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (cleanup(game),
			perror("Error\nError to open the file to read the map"), 0);
	i = 0;
	while (i < game->map_height)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		game->map[i] = ft_strtrim(buffer, "\n");
		if (!(game->map[i]))
			return (free(buffer), cleanup(game),
				perror("Error\nAllocation for the buffer failed"), 0);
		free(buffer);
		i++;
	}
	game->map[i] = NULL;
	game->map_width = ft_strlen(game->map[0]);
	close(fd);
	return (1);
}

int	create_map(t_game *game, char *filename)
{
	game->map_height = get_map_height(filename);
	if (game->map_height <= 0)
		return (ft_printf("Error\nThis map is empty\n"), 0);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!game->map)
		return (perror("Error\nAllocation memory for the map failed"), 0);
	return (1);
}
