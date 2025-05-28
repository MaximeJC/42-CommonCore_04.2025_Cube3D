#include "cub3d.h"

//Le fichier doit finir absolument par .cub

int	check_mapfile(char *str)
{
	if (ft_strncmp(&str[ft_strlen(str) - 4], ".cub", 5) != 0)
	{
		ft_putendl_fd(ERR_MAP_FILE, 2);
		return (1);
	}
	return (0);
}
