/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:03:35 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/05 14:41:18 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img, x*SCALE, y*SCALE);
}

static void	draw_floor(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
			put_image(game, game->floor.image, x, y);
	}
}

static void	display_moves(t_game *game)
{
	char	*moves_str;
	char	*ptr;

	ptr = ft_itoa(game->player.moves);
	moves_str = ft_strjoin("Moves: ", ptr);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, 0xFFFFFF, moves_str);
	free(ptr);
	free(moves_str);
}

void	render_game(t_game *game)
{
	int		x;
	int		y;
	char	c;

	draw_floor(game);
	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			c = game->map[y][x];
			if (c == '1')
				put_image(game, game->wall.image, x, y);
			if (c == 'E')
				put_image(game, game->exit.image, x, y);
			if (c == 'C')
				put_image(game, game->collect.image, x, y);
		}
	}
	put_image(game, game->player.image.image, game->player.position.x,
		game->player.position.y);
	display_moves(game);
	print_map(game->map);
}

int	init_images(t_game *game)
{
	game->floor.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/floor.xpm", &game->floor.width, &game->floor.height);
	game->wall.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/wall.xpm", &game->wall.width, &game->wall.height);
	game->player.image.image = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/player_1.xpm", &game->player.image.width,
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
