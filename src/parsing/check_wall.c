#include "cub3d.h"

char	**ft_strtab_dup(char **tab);
int	get_d_pos(char **c_map);
int	follow_wall(char **c_map, int d_x, int d_y);
void ft_print_tab(char **tab);

int	check_wall(t_data *data)
{
	int		d_x;
	int		d_y;
	char	**c_map;

	c_map = ft_strtab_dup(data->d_map->map);
	if(!c_map)
		return(error_handler(ERR_MALLOC, NULL, 0), 1);
	d_x = get_d_pos(c_map);
	d_y = 0;
	if (follow_wall(c_map, d_x, d_y) != 0)
		return (ft_strtab_free(c_map), error_handler(ERR_WALL, NULL, 0), 1);
	return (ft_strtab_free(c_map), 0);
}

char	**ft_strtab_dup(char **tab)
{
	int		i;
	char	**t_tab;

	i = 0;
	t_tab = ft_calloc((ft_strtab_size(tab) + 1), sizeof(char *));
	if (!t_tab)
		return (NULL);
	while(tab[i])
	{
		t_tab[i] = ft_strdup(tab[i]);
		if (!t_tab[i])
			return(ft_strtab_free(t_tab), NULL);
		i++;
	}
	t_tab[i] = NULL;
	return (t_tab);
}

int	get_d_pos(char **c_map)
{
	int	i;

	i = 0;
	while (c_map[0][i])
	{
		ft_printf("<%c>\n", c_map[0][i]);
		if (c_map[0][i] != ' ' && c_map[0][i] != '1' )
			return(error_handler(ERR_CHAR, NULL, 0), -1);
		if (c_map[0][i] == '1')
			return(i);
		i++;
	}
	return(error_handler("Error: Invalid Map.", NULL, 0), -1);
}
int	follow_wall(char **c_map, int d_x, int d_y)
{
	int	c_x;
	int	c_y;
	int	finish;

	c_x = d_x;
	c_y	= d_y;
	if (c_map[c_y][c_x] == '2')
		return (0);
	c_map[c_y][c_x] = '2';
	ft_print_tab(c_map);
	finish = 1;
	if (c_map[c_y][c_x + 1] == '1')
		finish = follow_wall(c_map, c_x + 1, c_y);
	if (c_map[c_y][c_x - 1] == '1')
		finish = follow_wall(c_map, c_x - 1, c_y);
	if (c_map[c_y + 1][c_x] == '1')
		finish = follow_wall(c_map, c_x, c_y + 1);
	if (c_map[c_y][c_x - 1] == '1')
		finish = follow_wall(c_map, c_x, c_y - 1);
	if (finish != 0)
		return (1);
	return (0);
}

void ft_print_tab(char **tab)
{
	int i;
	
	i = 0;
	while(tab[i])
	{
		ft_putendl_fd(tab[i], 1);
		i++;
	}
	ft_putendl_fd("", 1);

	return ;
}