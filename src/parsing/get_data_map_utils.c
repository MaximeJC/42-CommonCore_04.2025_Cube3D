#include "cub3d.h"

int	check_around(char **c_map, t_data *data, int i, int j);

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

int	check_carac(char **c_map, t_data *data)
{
	int	i;
	int	j;
	int	f_err;

	i = -1;
	f_err = 0;
	while (c_map[++i])
	{
		j = -1;
		while (c_map[i][++j])
		{
			f_err = check_around(c_map, data, i, j);
			if (f_err >= 4)
				return (error_handler(ERR_CHAR, NULL, 0), 1);
		}
	}
	return (0);
}

int	check_around(char **c_map, t_data *data, int i, int j)
{
	int	f_err;

	f_err = 0;
	if (!ft_isinset(c_map[i][j], " 1") && i == 0)
		f_err++;
	else if (!ft_isinset(c_map[i][j], " 1")
		&& ft_isinset(c_map[i - 1][j], " 1\0"))
		f_err++;
	if (!ft_isinset(c_map[i][j], " 1")
		&& i == data->d_map->height - 1)
		f_err++;
	else if (!ft_isinset(c_map[i][j], " 1")
		&& ft_isinset(c_map[i + 1][j], " 1\0"))
		f_err++;
	if (!ft_isinset(c_map[i][j], " 1") && j == 0)
		f_err++;
	else if (!ft_isinset(c_map[i][j], " 1")
		&& ft_isinset(c_map[i][j - 1], " 1\0"))
		f_err++;
	if (!ft_isinset(c_map[i][j], " 1") && j == data->d_map->width - 1)
		f_err++;
	else if (!ft_isinset(c_map[i][j], " 1")
		&& ft_isinset(c_map[i][j + 1], " 1\0"))
		f_err++;
	return (f_err);
}
