/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:26 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/10 18:56:48 by alfavre          ###   ########.fr       */
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

static int	game_init(t_game *game, char *filename)
{
	init_game_struct(game);
	if (!validate_map(game, filename))
		return (cleanup(game), ft_printf("Map no valid\n"), 0);
	if (!init_window(game))
		return (cleanup(game), ft_printf("Window error\n"), 0);
	if (!init_images(game))
		return (cleanup(game), ft_printf("Error\nImage error\n"), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*extension;

	if (argc != 2)
		return (ft_printf("Error\nNeed: ./so_long map.ber\n"), 1);
	extension = ft_strrchr(argv[1], '.');
	if (!extension || (!ft_strncmp(extension, ".ber", 4) == 0))
		return (ft_printf("Error\nInvalid map extension. Must be a .ber\n"), 1);
	if (!game_init(&game, argv[1]))
		return (ft_printf("Impossible to create the game\n"), 1);
	render_game(&game);
	setup_game_controls(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
