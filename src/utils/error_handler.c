#include "cub3d.h"

void	error_handler(char *msg, t_data *data, int i_exit)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	if (i_exit)
		exit(0);
	(void)data;
}
