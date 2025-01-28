/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:25:57 by alfavre           #+#    #+#             */
/*   Updated: 2025/01/28 15:43:43 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/include/libft.h"
# include "../mlx/mlx.h"

typedef struct s_map
{
	int	high;
	int	length;
	int	pos_x;
	int	pos_y;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*textures[5];
	t_map	*map;
}	t_data;


#endif