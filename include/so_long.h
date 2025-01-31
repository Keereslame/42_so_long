/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:25:57 by alfavre           #+#    #+#             */
/*   Updated: 2025/01/31 10:25:58 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_player
{
	t_position	position;
	void		*sprite;
}	t_player;

typedef struct s_collectible
{
	t_position	position;
	void		*sprite;
}	t_collectible;

typedef struct s_exit
{
	t_position	position;
	void		*sprite;
}	t_exit;

typedef struct s_map
{
	int				height;
	int				width;
	t_collectible	*collectibles;
	t_exit			exit;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*sprites[5];
	t_map	*map;
}	t_data;

int	on_destroy(t_data *data);
int	on_keypress(int key_sym, t_data *data);

#endif