#include "so_long.h"

int	on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int key_sym, t_game *game)
{
	(void)game;
	ft_printf("Pressed key : %d\n", key_sym);
	return (0);
}
