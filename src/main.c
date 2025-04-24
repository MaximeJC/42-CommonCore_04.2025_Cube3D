#include "cub3d.h"

int check_arg(int argc)
{
	if (argc > 2)
		return (ft_putendl_fd(ERR_TM_ARG, 2), 1);
	else if (argc < 2)
		return (ft_putendl_fd(ERR_NE_ARG, 2), 1);
	return (0);
}

int main(int argc, char const *argv[])
{
	if(check_arg(argc) != 0)
		return (1);
	(void)argv;
	printf("Hello world!");
	return 0;
}
