/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:25:57 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/02 11:30:09 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <fcntl.h>

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
	char		state; //open(1) or close(0)
}	t_exit;

typedef struct s_map
{
	size_t	height;
	size_t	width;
	char	**values;
	int		nb_collectible;
	int		nb_player;
	int		nb_exit;
}	t_map;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			map;
	t_collectible	*collectibles;
	t_player		player;
	t_exit			exit;
}	t_data;

int		on_destroy(t_data *data);
int		on_keypress(int key_sym, t_data *data);
void	check_map(char *file, t_data *data);
void	free_map(t_data *data);

#endif