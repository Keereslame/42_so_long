/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:26 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/03 11:18:31 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argv;
	(void)argc;
	ft_memset(&game, 0, sizeof(t_game));
	if (!create_map(&game, "map/map1.ber"))
	{
		ft_printf("Error\nInvalid map\n");
		return (free_map(game.map), 1);
	}
	print_map(&game);
	return (free_map(game.map), 0);
	/*data.mlx_ptr = mlx_init();
	if (!(data.mlx_ptr))
		return (perror("Mlx init() failed"), 1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "so_long");
	if (!(data.win_ptr))
		return (free(data.mlx_ptr), perror("Mlx new_window() failed"), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &data);
	mlx_loop(data.mlx_ptr);
	return (0);*/
}
