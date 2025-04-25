#include "cub3d.h"

int	check_arg(int argc)
{
	if (argc > 2)
		return (ft_putendl_fd(ERR_TM_ARG, 2), 1);
	else if (argc < 2)
		return (ft_putendl_fd(ERR_NE_ARG, 2), 1);
	return (0);
}

int	main(int argc, char const *argv[])
{
	t_data	data;

	if (check_arg(argc) || check_mapfile((char *)argv[1]))
		return (1);
	if (init_data(&data, (char *)argv[1]))
		return (clear_data(&data), 1);
	if (get_data_map(&data) != 0)
		return (clear_data(&data), 1);
	return (clear_data(&data), 0);
}
