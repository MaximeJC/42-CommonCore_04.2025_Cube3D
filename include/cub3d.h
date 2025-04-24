#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <errno.h>
# include <fcntl.h>
# include <math.h>

//Map struct
	typedef struct s_map
	{
		char	*no_texture;
		char	*so_texture;
		char	*we_texture;
		char	*ea_texture;
		int		f_rgb[4];
		int		c_rgb[4];
		char	**map;
	}			t_map;

//Global data struct
	typedef struct s_data
	{
		char	*filename;
		t_map	*d_map;
	}			t_data;

//* Error messages - Global
# define ERR_MALLOC "Error: Malloc Error"

//* Error messages - Map check
# define ERR_ARGS "Usage: ./cub3D <map.cub>"
# define ERR_MAP_FILE "Error: Invalid file format. Expected a '.cub' file."
# define ERR_TM_ARG "Error: Too many arguments. Usage: ./program map_file.cun"
# define ERR_NE_ARG "Error: Not enough arguments. Usage: ./program map_file.cun"
# define ERR_NRGB "Error: Invalid color format. Use RGB format as 'R,G,B'."

//* Error messages - MLX
# define ERR_MLXD_INIT "mlx_data init error"
# define ERR_MLX_INIT "mlx init error"
# define ERR_WIN_INIT "Window init error"
# define ERR_IMG_INIT "Sprites init error"

//* Functions' shortcut
# define MLX_IMG_WIN mlx_put_image_to_window
# define MLX_IMG_INIT mlx_xpm_file_to_image

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

//* parsing
// -> check_mapfile
int check_mapfile(char *str);
// -> get_data_map
int get_data_map(t_data **data);
// -> get_map
// -> get_data-map_utils
int check_empty_line(char *line, int err);
void check_data_error(char *sterr, int err);

//* utils
// -> error_handler
void error_handler(char *msg, t_data **data, int exit);

#endif
