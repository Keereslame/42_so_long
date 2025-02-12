/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:03:35 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/10 14:19:40 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img, x * TILE_SIZE, y * TILE_SIZE);
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

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			c = game->map[y][x];
			if (c == '0')
				put_image(game, game->floor.image, x, y);
			if (c == '1')
				put_image(game, game->wall.image, x, y);
			if (c == 'E')
				put_image(game, game->exit.image, x, y);
			if (c == 'C')
				put_image(game, game->collect.image, x, y);
			if (c == 'P')
				put_image(game, game->player.image.image, x, y);
		}
	}
	display_moves(game);
}
