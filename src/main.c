#include "cub3d.h"

int	check_arg(int argc)
{
	if (argc > 2)
		return (ft_putendl_fd(ERR_TM_AR, 2), 1);
	else if (argc < 2)
		return (ft_putendl_fd(ERR_NE_AR, 2), 1);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	if (check_arg(argc) || check_mapfile((char *)argv[1]))
		return (1);
	if (init_data(&data, (char *)argv[1]))
		return (clear_data(&data), 1);
	if (get_data_map(&data, 0) != 0)
		return (clear_data(&data), 1);
	if (check_wall_and_ground(&data) != 0)
		return (clear_data(&data), 1);
	ft_print_tab(data.d_map->map);
	mlx_win_init(&data);
	ft_printf("Mlx initialized\n");
	display_once(&data);
	usleep(3000000); // 3 sec
	return (clear_data(&data), 0);
}
