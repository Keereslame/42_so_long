/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:40:56 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/03 11:16:30 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_height(char *file)
{
	int		fd;
	char	*buffer;
	size_t	height;

	height = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Error to open the map's file"), 0);
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

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map_height)
	{
		while (j < game->map_width)
			ft_printf("%c", game->map[i][j++]);
		ft_printf("\n");
		j = 0;
		i++;
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i++]);
	}
	free(map);
}
