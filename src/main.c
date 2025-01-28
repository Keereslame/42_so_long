/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:33:26 by alfavre           #+#    #+#             */
/*   Updated: 2025/01/28 13:42:08 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_window;

	(void)argc;
	(void)argv;
	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, 500, 500, "so_long");
	(void)mlx_window;
	mlx_loop(mlx_ptr);
}
