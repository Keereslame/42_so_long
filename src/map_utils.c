/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:12:26 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/02 16:14:44 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_data *data)
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
