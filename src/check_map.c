/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:02:54 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/02 11:44:12 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_map(t_data *data, size_t height, size_t width)
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

static void	map_init(char *file, t_data *data)
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

static void	print_map(t_data *data)
{
	size_t	height;
	size_t	width;

	height = 0;
	width = 0;
	while (height < data->map.height)
	{
		while (width < data->map.width)
			ft_printf("%c", data->map.values[height][width++]);
		ft_printf("\n");
		width = 0;
		height++;
	}
}

void	free_map(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->map.height)
		free(data->map.values[i++]);
	free(data->map.values);
}

void	check_map(char *file, t_data *data)
{
	int		fd;
	char	*buffer;
	size_t	height;
	size_t	width;

	height = 0;
	width = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("Error to open the map's file");
	buffer = get_next_line(fd);
	while (buffer)
	{
		if (!width)
			width = ft_strlen(buffer) - 1;
		else
		{
			if (width != (ft_strlen(buffer)- 1))
			{
				ft_printf("This is not a rectangle");
				return ;
			}
		}
		height++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	close(fd);
	create_map(data, height, width);
	map_init(file, data);
	print_map(data);
}
