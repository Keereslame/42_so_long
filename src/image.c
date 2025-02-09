/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:28:11 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/09 17:03:43 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_images(t_game *game)
{
	game->floor.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/floor.xpm", &game->floor.width, &game->floor.height);
	game->wall.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/wall.xpm", &game->wall.width, &game->wall.height);
	game->player.image.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/player_walk.xpm", &game->player.image.width,
			&game->player.image.height);
	game->collect.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/collectible.xpm", &game->collect.width,
			&game->collect.height);
	game->exit.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/exit_close.xpm", &game->exit.width,
			&game->exit.height);
	return (game->floor.image && game->wall.image && game->player.image.image
		&& game->collect.image && game->exit.image);
}
