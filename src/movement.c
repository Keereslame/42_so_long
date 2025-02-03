/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:17:48 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/03 17:39:10 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game *game, int new_x, int new_y)
{
	char	value;

	value = game->map[new_y][new_x];
	if (value == '1')
		return (0);
	if (value == 'C')
	{
		game->player.collectibles++;
		game->map[new_y][new_x] = '0';
	}
	else if (value == 'E')
	{
		if (game->player.collectibles == game->nb_collectibles)
			game->game_over = 1;
		else
			return (0);
	}
	return (1);
}

void	update_position(t_game *game, int new_x, int new_y)
{
	if (can_move(game, new_x, new_y))
	{
		game->player.position.x = new_x;
		game->player.position.y = new_y;
		game->player.moves++;
		ft_printf("Moves: %d\n", game->player.moves);
	}
}

void	setup_game_controls(t_game *game)
{
	mlx_hook(game->win_ptr, 2, 1L<<0, on_keypress, game);
	mlx_hook(game->win_ptr, 17, 1L<<17, on_destroy, game);
}
