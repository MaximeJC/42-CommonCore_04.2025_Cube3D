#include "cub3d.h"

int	get_texture(t_data *data, char *line, int err);
int	get_rgb(t_data *data, char *line, int i, char **tmp);
int	check_rgb(char **tmp);
int	check_data(t_data *data, int c, int err);

int	get_data_map(t_data *data, int fd)
{
	int		i;
	int		err;
	char	*line;

	i = 0;
	err = 0;
	fd = open(data->filename, O_RDONLY);
	if (fd < 0)
		return (error_handler(ERR_NAME_FILE, NULL, 0), 1);
	line = get_next_line(fd);
	while (line)
	{
		err += check_empty_line(line, err);
		err += get_texture(data, line, err);
		err += get_rgb(data, line, -1, NULL);
		free(line);
		line = get_next_line(fd);
		if (check_data(data, 0, err) == 0 && err == 0)
			err += get_map(data, &line, fd);
	}
	if (check_data(data, 1, err) == 1)
		return (close(fd), 1);
	if (err > 0)
		return (close(fd), 1);
	return (close(fd), 0);
}

int	get_texture(t_data *data, char *line, int err)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && err == 0)
	{
		data->d_map->no_texture = ft_strtrim(&line[2], "  \n");
		if (data->d_map->no_texture == NULL)
			return (ft_putendl_fd(ERR_MALLOC, 2), 1);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0 && err == 0)
	{
		data->d_map->so_texture = ft_strtrim(&line[2], " \n");
		if (data->d_map->so_texture == NULL)
			return (ft_putendl_fd(ERR_MALLOC, 2), 1);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0 && err == 0)
	{
		data->d_map->ea_texture = ft_strtrim(&line[2], " \n");
		if (data->d_map->ea_texture == NULL)
			return (ft_putendl_fd(ERR_MALLOC, 2), 1);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0 && err == 0)
	{
		data->d_map->we_texture = ft_strtrim(&line[2], " \n");
		if (data->d_map->we_texture == NULL)
			return (ft_putendl_fd(ERR_MALLOC, 2), 1);
	}
	return (0);
}

int	get_rgb(t_data *data, char *line, int i, char **tmp)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		tmp = ft_split(&line[2], ',');
		if (tmp == NULL)
			return (ft_putendl_fd(ERR_MALLOC, 2), 1);
		if (data->d_map->f_rgb != -1 || check_rgb(tmp) != 0)
			return (ft_strtab_free(tmp), ft_putendl_fd(ERR_NRGB, 2), 1);
		data->d_map->f_rgb = create_rgb(ft_atoi(tmp[0]),
				ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		ft_strtab_free(tmp);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		i = -1;
		tmp = ft_split(&line[2], ',');
		if (tmp == NULL)
			return (ft_putendl_fd(ERR_MALLOC, 2), 1);
		if (data->d_map->c_rgb != -1 || check_rgb(tmp) != 0)
			return (ft_strtab_free(tmp), ft_putendl_fd(ERR_NRGB, 2), 1);
		data->d_map->c_rgb = create_rgb(ft_atoi(tmp[0]),
				ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		ft_strtab_free(tmp);
	}
	return (0);
}

int	check_rgb(char **tmp)
{
	if (ft_strtab_size(tmp) != 3)
		return (1);
	else if (ft_isnumber(tmp[0]) == 0 || ft_isnumber(tmp[1]) == 0
		|| ft_isnumber(tmp[2]) == 0)
		return (1);
	else if ((ft_atoi(tmp[0]) > 255 || ft_atoi(tmp[0]) < 0)
		|| (ft_atoi(tmp[1]) > 255 || ft_atoi(tmp[1]) < 0)
		|| (ft_atoi(tmp[2]) > 255 || ft_atoi(tmp[2]) < 0))
		return (1);
	return (0);
}

int	check_data(t_data *data, int c, int err)
{
	int	i;

	i = -1;
	if (err != 0)
		return (1);
	if (data->d_map->no_texture == NULL)
		return (check_data_error("Error\nNorth texture is missing", c), 1);
	else if (data->d_map->so_texture == NULL)
		return (check_data_error("Error\nSouth texture is missing", c), 1);
	else if (data->d_map->we_texture == NULL)
		return (check_data_error("Error\nWest texture is missing", c), 1);
	else if (data->d_map->ea_texture == NULL)
		return (check_data_error("Error\nEast texture is missing", c), 1);
	if (data->d_map->c_rgb == -1 || data->d_map->f_rgb == -1)
		return (1);
	return (0);
}
