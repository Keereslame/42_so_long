/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:44:22 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/03 17:33:41 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_game *game)
{
	int	x;
	int	y;

	ft_printf("Pressed key : %d\n", keycode);
	x = game->player.position.x;
	y = game->player.position.y;
	if (game->game_over)
		return (0);
	if (keycode == KEY_ESC)
	{
		free_map(game->map);
		exit(0);
	}
	else if (keycode == KEY_W || keycode == KEY_UP)
		y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		x++;
	else
		return (0);
	update_position(game, x, y);
	//render_game(game);
	return (0);
}
