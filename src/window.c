/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:26:19 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/09 11:29:03 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_window_size(t_game *game)
{
	int	screen_width;
	int	screen_height;
	int	window_width;
	int	window_height;

	mlx_get_screen_size(game->mlx_ptr, &screen_width, &screen_height);
	game->tile_size = 64;
	window_width = game->map_width * game->tile_size;
	window_height = game->map_height * game->tile_size;
	if (window_width > screen_width * 0.8)
	{
		window_width = screen_width * 0.8;
		game->tile_size = window_width / game->map_width;
		window_height = game->map_height * game->tile_size;
	}
	if (window_height > screen_height * 0.8)
	{
		window_height = screen_height * 0.8;
		game->tile_size = window_height / game->map_height;
		window_width = game->map_width * game->tile_size;
	}
	game->win_width = window_width;
	game->win_height = window_height;
}

int	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	get_window_size(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_width,
			game->win_height, "so_long");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		return (0);
	}
	return (1);
}

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}
