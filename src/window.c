/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 10:26:19 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/09 16:59:03 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_size(t_game *game, int screen_width, int screen_height)
{
	if (game->win_width > screen_width)
		return (ft_printf("Error\nMap too large\n"), 0);
	if (game->win_height > screen_height)
		return (ft_printf("Error\nMap too height\n"), 0);
	return (1);
}

static int	get_window_size(t_game *game)
{
	int	screen_width;
	int	screen_height;
	int	window_width;
	int	window_height;

	mlx_get_screen_size(game->mlx_ptr, &screen_width, &screen_height);
	game->tile_size = 64;
	window_width = game->map_width * game->tile_size;
	window_height = game->map_height * game->tile_size;
	game->win_width = window_width;
	game->win_height = window_height;
	return (check_size(game, screen_width, screen_height));
}

int	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	if (!get_window_size(game))
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_width,
			game->win_height, "so_long");
	if (!game->win_ptr)
		return (0);
	return (1);
}

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}
