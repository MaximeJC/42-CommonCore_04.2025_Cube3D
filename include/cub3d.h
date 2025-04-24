#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <errno.h>
# include <fcntl.h>
# include <math.h>

//* Error messages - Map check
# define ERR_ARGS "Usage: ./cub3D <map.cub>"
# define ERR_MAP_FILE "Error: Invalid file format. Expected a '.cub' file."
# define ERR_TM_ARG "Error: Too many arguments. Usage: ./your_program map_file.cun"
# define ERR_NE_ARG "Error: Not enough arguments. Usage: ./your_program map_file.cun"

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

#endif
