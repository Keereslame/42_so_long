#include "so_long.h"

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int key_sym, t_data *data)
{
	(void)data;
	ft_printf("Pressed key : %d\n", key_sym);
	return (0);
}
