/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:26 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/03 17:38:13 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argv;
	(void)argc;
	ft_memset(&game, 0, sizeof(t_game));
	if (!validate_map(&game,
			"/home/alfavre/Documents/42_github/42_so_long/map/map1.ber"))
		return (free_map(game.map), ft_printf("Error\nInvalid map\n"), 1);
	print_map(game.map);
	game.mlx_ptr = mlx_init();
	if (!(game.mlx_ptr))
		return (perror("Mlx init() failed"), 1);
	game.win_ptr = mlx_new_window(game.mlx_ptr, 500, 500, "so_long");
	if (!(game.win_ptr))
		return (free(game.mlx_ptr), perror("Mlx new_window() failed"), 1);
	setup_game_controls(&game);
	mlx_loop(game.mlx_ptr);
	return (free_map(game.map), 0);
}
