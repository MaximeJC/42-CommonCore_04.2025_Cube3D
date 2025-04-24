#include "cub3d.h"

int init_data(t_data **data, char const *filename)
{	
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
	t_data *data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (ft_putendl_fd(ERR_MALLOC, 2), 1);

	if (check_arg(argc) != 0)
		return (1);
	if (check_mapfile((char *)argv[1]) != 0)
		return (1);
	if (init_data(&data, argv[1]) != 0)
		return (1);
	if (get_data_map(&data) != 0)
		return (1);

	ft_putendl_fd("NO ", 1);
	ft_putendl_fd(data->d_map->no_texture, 1);
	ft_putendl_fd("SO ", 1);
	ft_putendl_fd(data->d_map->so_texture, 1);
	ft_putendl_fd("WE ", 1);
	ft_putendl_fd(data->d_map->we_texture, 1);
	ft_putendl_fd("EA ", 1);
	ft_putendl_fd(data->d_map->ea_texture, 1);

	ft_printf("f %d,%d,%d\n", data->d_map->f_rgb[0], data->d_map->f_rgb[1], data->d_map->f_rgb[2]);
	ft_printf("f %d,%d,%d\n", data->d_map->c_rgb[0], data->d_map->c_rgb[1], data->d_map->c_rgb[2]);
	return (0);
}
