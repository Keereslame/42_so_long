/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfavre <alfavre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:25:57 by alfavre           #+#    #+#             */
/*   Updated: 2025/02/10 14:25:05 by alfavre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <fcntl.h>
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_ESC 65307
# define TILE_SIZE 64

typedef struct s_flood
{
	char	**map;
	int		height;
	int		width;
	int		collectibles;
	int		exit_found;
}	t_flood;

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_image
{
	void	*image;
	int		width;
	int		height;
}	t_image;

typedef struct s_player
{
	t_image		image;
	t_position	position;
	int			moves;
	int			collectibles;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			map_width;
	int			map_height;
	t_image		wall;
	t_image		floor;
	t_image		collect;
	t_image		exit;
	t_player	player;
	int			game_over;
	int			nb_player;
	int			nb_exit;
	int			nb_collectibles;
	int			win_width;
	int			win_height;
}	t_game;

/*map*/
int		create_map(t_game *game, char *filename);
int		read_map(t_game *game, char *filename);
int		check_map(t_game *game);
int		validate_map(t_game *game, char *filename);

/*map_utils*/
void	free_map(char **map);
void	print_map(char **map);
int		get_map_height(char *file);

/*movements*/
void	setup_game_controls(t_game *game);
void	update_position(t_game *game, int new_x, int new_y);

/*events*/
int		on_destroy(t_game *data);
int		on_keypress(int key_sym, t_game *data);

/*clean*/
void	clean_mlx(t_game *game);
void	cleanup(t_game *game);

/*image*/
int		init_images(t_game *game);

/*render*/
void	render_game(t_game *game);

/*window*/
int		init_window(t_game *game);

#endif