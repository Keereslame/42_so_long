/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:28:11 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/07 17:46:18 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*scale_image(t_game *game, void *original)
{
	void	*new_image;
	size_t	new_width;
	size_t	new_height;

	new_width = (game->map_width * WINDOW_WIDTH)
		/ (game->map_width * ORIGINAL__TILE_SIZE);
	new_height = (game->map_height * WINDOW_HEIGHT)
		/ (game->map_height * ORIGINAL__TILE_SIZE);
	new_image = mlx_new_image(game->mlx_ptr, new_width, new_height);
	mlx_put_image_to_window(game->mlx_ptr, new_image, original, 0, 0);
	return (new_image);
}

int	min_size(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
