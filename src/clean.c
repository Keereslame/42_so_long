/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 07:47:51 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/10 14:25:05 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_mlx(t_game *game)
{
	if (game->player.image.image)
		mlx_destroy_image(game->mlx_ptr, game->player.image.image);
	if (game->wall.image)
		mlx_destroy_image(game->mlx_ptr, game->wall.image);
	if (game->exit.image)
		mlx_destroy_image(game->mlx_ptr, game->exit.image);
	if (game->collect.image)
		mlx_destroy_image(game->mlx_ptr, game->collect.image);
	if (game->floor.image)
		mlx_destroy_image(game->mlx_ptr, game->floor.image);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
}

void	cleanup(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	clean_mlx(game);
}
