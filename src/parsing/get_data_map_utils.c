#include "cub3d.h"

int	check_empty_line(char *line, int err)
{
	if (ft_strncmp(line, "SO ", 3) == 0 || ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0 || ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "C ", 2) == 0 || ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "\n", 2) == 0)
		return (0);
	if (err != 0)
		return (1);
	return (ft_putendl_fd("invalid File", 2), 1);
}

void	check_data_error(char *sterr, int err)
{
	if (err == 1)
		error_handler(sterr, NULL, 0);
}

void	get_size_map(t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	data->d_map->height = ft_strtab_size(data->d_map->map);
	while (data->d_map->map[i])
	{
		if (ft_strlen(data->d_map->map[i]) > len)
			len = ft_strlen(data->d_map->map[i]);
		i++;
	}
	data->d_map->width = len;
	ft_printf("h = %d, l = %d", data->d_map->height, data->d_map->width);
}
