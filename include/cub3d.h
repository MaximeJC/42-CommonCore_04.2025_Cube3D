#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <errno.h>
# include <fcntl.h>
# include <math.h>

//* Global data struct
typedef struct s_data
{
	char				*filename;
	void				*mlx_ptr;
	void				*mlx_win;
	struct s_map		*d_map;
	struct s_player		*player;
}						t_data;

//* Map struct
typedef struct s_map
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	void	*no_text_mlx;
	void	*so_text_mlx;
	void	*we_text_mlx;
	void	*ea_text_mlx;
	int		f_rgb[3];
	int		c_rgb[3];
	int		height;
	int		width;
	char	**map;
}			t_map;

//* Player struct
typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;
}			t_player;

typedef struct s_raycast
{
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;
}			t_raycast;

//* Error messages - Global
# define ERR_MALLOC "Error\nMalloc Error"

//* Error messages - Map check
# define ERR_ARGS "Error\nUsage: ./cub3D <map.cub>"
# define ERR_NAME_FILE "Error\nInvalid file. Can't open file."
# define ERR_MAP_FILE "Error\nInvalid file format. Expected a '.cub' file."
# define ERR_TM_AR "Error\nToo many arguments. Usage: ./program map_file.cub"
# define ERR_NE_AR "Error\nNot enough arguments. Usage: ./program map_file.cub"
# define ERR_NRGB "Error\nInvalid color format. Use RGB format as 'R,G,B'."
# define ERR_CHAR "Error\nInvalid character in map."
# define ERR_WALL "Error\nWall not completed"
# define ERR_TM_PLY "Error\nToo many players. Usage: One player."
# define ERR_NE_PLY "Error\nNot enough players. Usage: One player."

//* Error messages - MLX
# define ERR_MLX_INIT "Error\nMlx init error"
# define ERR_WIN_INIT "Error\nWindow init error"
# define ERR_IMG_INIT "Error\nSprites init error"

//* Functions' shortcut
# define MLX_IMG_WIN mlx_put_image_to_window
# define MLX_IMG_INIT mlx_xpm_file_to_image

//* Game parameters
# define WIDTH 1920
# define HEIGHT 1000
# define IMG_SIZE 512

//* Keyboard keys
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

//* game_engine
// -> mlx_manegement
void	mlx_win_init(t_data *data);

//* parsing
// -> check_mapfile
int		check_mapfile(char *str);
// -> get_data_map
int		get_data_map(t_data *data, int fd);
// -> get_map
int		get_map(t_data *data, char **line, int fd);
// -> get_data-map_utils
int		check_empty_line(char *line, int err);
void	check_data_error(char *sterr, int err);
// -> check_wall
int		check_wall_and_ground(t_data *data);
// -> check_wall_utils
char	**ft_strtab_dup(char **tab);
void	ft_print_tab(char **tab);
void	get_size_map(t_data *data);
int		check_carac(char **c_map, t_data *data);

//* struct
// -> struct_data
int		init_data(t_data *data, char *file);
void	clear_data(t_data *data);
// -> struct_map
int		init_map(t_data *data);
void	clear_map(t_data *data);
// -> struct_player
int		init_player(t_data *data);
void	clear_player(t_data *data);
// -> struct_raycast
int		init_raycast(t_raycast *ray);

//* utils
// -> error_handler
void	error_handler(char *msg, t_data *data, int exit);

#endif
