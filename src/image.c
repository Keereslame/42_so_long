/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 20:28:11 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/09 14:32:48 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	debug_image_size(t_game *game)
{
	ft_printf("Image sizes:\n");
	ft_printf("Floor: %dx%d\n", game->floor.width, game->floor.height);
	ft_printf("Wall: %dx%d\n", game->wall.width, game->wall.height);
	ft_printf("Player: %dx%d\n", game->player.image.width, game->player.image.height);
	ft_printf("Collectible: %dx%d\n", game->collect.width, game->collect.height);
	ft_printf("Exit: %dx%d\n", game->exit.width, game->exit.height);
}

static void	scale_size(t_game *game)
{
	game->exit.width /= game->tile_size;
	game->exit.height /= game->tile_size;
	game->floor.width /= game->tile_size;
	game->floor.height /= game->tile_size;
	game->wall.width /= game->tile_size;
	game->wall.height /= game->tile_size;
	game->collect.width /= game->tile_size;
	game->collect.height /= game->tile_size;
	game->player.image.width /= game->tile_size;
	game->player.image.height /= game->tile_size;
}

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
	debug_image_size(game);
	scale_size(game);
	debug_image_size(game);
	return (game->floor.image && game->wall.image && game->player.image.image
		&& game->collect.image && game->exit.image);
}
