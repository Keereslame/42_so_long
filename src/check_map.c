/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:02:54 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/02 16:11:57 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
