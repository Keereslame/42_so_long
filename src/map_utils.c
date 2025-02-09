/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:40:56 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/09 20:35:51 by alfavre          ###   ########.fr       */
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
		return (perror("Error\nError to open the map's file"), 0);
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

void	print_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			ft_printf("%c", map[i][j]);
		ft_printf("\n");
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}
