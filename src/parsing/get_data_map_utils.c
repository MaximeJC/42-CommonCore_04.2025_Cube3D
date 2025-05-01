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

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
