/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:26 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/02 11:18:59 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	(void)argc;
	ft_bzero(&data, sizeof(t_data));
	check_map("/home/alfavre/Documents/42_github/42_so_long/map/map1.ber", &data);
	free_map(&data);
	return (0);
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
