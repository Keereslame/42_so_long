/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:02:54 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/01 19:00:19 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_map(t_data *data, size_t height, size_t width)
{
	t_map	map;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	map.height = height;
	map.nb_collectible = 0;
	map.nb_exit = 0;
	map.nb_player = 0;
	map.width = width;
	map.values = malloc(sizeof(char) * (width * height));
	while (i < height)
	{
		while (j < width)
		{
			map.values[i][j] = malloc(sizeof(char) * 1);
			j++;
		}
		j = 0;
		i++;
	}
	data->map = map;
}

static void	map_init(char *file, t_data *data)
{
	char	*buffer;
	size_t	height;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("Error to open the map's file");
	height = 0;
	i = 0;
	buffer = get_next_line(fd);
	while (buffer)
	{
		while (*buffer)
			data->map.values[height][i++] = *(buffer++);
		height++;
		buffer = get_next_line(fd);
	}
	data->map.height = height;
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

int	check_map(char *file, t_data *data)
{
	int		fd;
	char	*buffer;
	size_t	height;
	size_t	width;
	size_t	temp_width;

	height = 0;
	width = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("Error to open the map's file");
	buffer = get_next_line(fd);
	while (buffer)
	{
		height++;
		if (!width)
			width = ft_strlen(buffer) - 1;
		else
		{
			temp_width = ft_strlen(buffer)- 1;
			if (width != temp_width)
			{
				ft_printf("This is not a rectangle");
				free(data->map.values);
				return (0);
			}
		}
		buffer = get_next_line(fd);
	}
	close(fd);
	create_map(data, height, width);
	map_init(file, data);
	print_map(data);
	return (0);
}
