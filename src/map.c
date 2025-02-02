/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:55:48 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/02 16:13:44 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_data *data, size_t height, size_t width)
{
	t_map	map;

	map.height = height;
	map.nb_collectible = 0;
	map.nb_exit = 0;
	map.nb_player = 0;
	map.width = width;
	map.values = malloc(sizeof(char *) * height);
	data->map = map;
}

void	map_init(char *file, t_data *data)
{
	char	*buffer;
	size_t	i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("Error to open the map's file");
	i = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		data->map.values[i] = ft_strdup(buffer);
		i++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
}


