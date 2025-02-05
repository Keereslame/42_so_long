/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:26 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/05 14:09:57 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game_struct(t_game *game)
{
	ft_memset(game, 0, sizeof(t_game));
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map = NULL;
	game->player.moves = 0;
	game->player.collectibles = 0;
	game->game_over = 0;
}

static int	init_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_width*SCALE,
			game->map_height*SCALE, "so_long");
	if (!game->win_ptr)
	{
		free(game->mlx_ptr);
		return (0);
	}
	return (1);
}

static int	game_init(t_game *game, char *filename)
{
	init_game_struct(game);
	if (!validate_map(game, filename))
		return (ft_printf("Error\nMap no valid\n"), 0);
	if (!init_window(game))
		return (free_map(game->map), 0);
	if (!init_images(game))
		return (cleanup(game), 0);
	return (1);
}

int	close_window(t_game *game)
{
	cleanup(game);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (ft_printf("Error\nNeed: ./so_long map.ber\n"), 1);
	if (!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		return (ft_printf("Error\nInvalid map extension\n"), 1);
	if (!game_init(&game, argv[1]))
		return (1);
	render_game(&game);
	mlx_hook(game.win_ptr, 2, 1L<<0, on_keypress, &game);
	mlx_hook(game.win_ptr, 17, 1L<<17, on_destroy, &game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
