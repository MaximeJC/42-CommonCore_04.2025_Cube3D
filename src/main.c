#include "cub3d.h"

int	init_map(t_data **data, char const *filename)
{
	int	i;

	i = -1;
	(*data)->d_map = malloc(sizeof(t_map));
	if ((*data)->d_map == NULL)
		return (ft_putendl_fd(ERR_MALLOC, 2), 1);
	(*data)->d_map->no_texture = NULL;
	(*data)->d_map->so_texture = NULL;
	(*data)->d_map->ea_texture = NULL;
	(*data)->d_map->we_texture = NULL;
	(*data)->filename = ft_strdup(filename);
	if ((*data)->filename == NULL)
		return (ft_putendl_fd(ERR_MALLOC, 2), 1);
	while (++i < 3)
	{
		(*data)->d_map->c_rgb[i] = -1;
		(*data)->d_map->f_rgb[i] = -1;
	}
	return (0);
}

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
