/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 10:44:22 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/10 14:32:49 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

int	on_keypress(int keycode, t_game *game)
{
	int	x;
	int	y;

	x = game->player.position.x;
	y = game->player.position.y;
	if (game->game_over)
		return (0);
	if (keycode == KEY_ESC)
		return (on_destroy(game), 0);
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
	render_game(game);
	if (game->game_over)
		return (ft_printf("Congratulations! You won!\n"), on_destroy(game), 0);
	return (0);
}
