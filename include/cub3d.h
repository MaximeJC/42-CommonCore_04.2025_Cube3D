/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolmar <nicolmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:45 by nicolmar          #+#    #+#             */
/*   Updated: 2025/05/13 15:25:38 by nicolmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <errno.h>
# include <fcntl.h>
# include <math.h>

//* Max keys
# define MAX_KEYS 65536

//* Global data struct
typedef struct s_data
{
	char				*filename;
	void				*mlx_ptr;
	void				*mlx_win;
	struct s_img		*img;
	struct s_map		*d_map;
	struct s_player		*player;
	struct s_raycast	*ray;
	int					keys[MAX_KEYS];
	int					mouse;
	char				*textures[4];
	int					text_bpp[4];
	int					text_line_len[4];
	int					text_endian[4];
}						t_data;

//* Screen img struct
typedef struct s_img
{
	void	*img;
	char	*img_addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_img;

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
	int		f_rgb;
	int		c_rgb;
	int		height;
	int		width;
	char	**map;
}			t_map;

//* Player struct
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plan_x;
	double	plan_y;
}			t_player;

//* Ray struct
typedef struct s_raycast
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	perp_wall_dist;
	int		line_height;
	int		draw_start_pix;
	int		draw_end_pix;
	int		x;
}			t_raycast;

//* Error messages - Global
# define ERR_MALLOC "Error\nMalloc Error"

//* Error messages - Map check
# define ERR_ARGS "Error\nUsage: ./cub3D <map.cub>"
# define ERR_INV_FILE "Error\nInvalid file."
# define ERR_NAME_FILE "Error\nInvalid file. Can't open file."
# define ERR_MAP_FILE "Error\nInvalid file format. Expected a '.cub' file."
# define ERR_TM_AR "Error\nToo many arguments. Usage: ./program map_file.cub"
# define ERR_NE_AR "Error\nNot enough arguments. Usage: ./program map_file.cub"
# define ERR_NRGB "Error\nInvalid color format. Use RGB format as 'R,G,B'."
# define ERR_CHAR "Error\nInvalid character in map."
# define ERR_WALL "Error\nWall not completed"
# define ERR_TM_PLY "Error\nToo many players. Usage: One player."
# define ERR_NE_PLY "Error\nNot enough players. Usage: One player."
# define ERR_TEXTURE "Error\nInvalid texture format. Use XPM format."
# define ERR_TEX_NB "Error\nToo many texture in file."

//* Error messages - MLX
# define ERR_MLX_INIT "Error\nMlx init error"
# define ERR_WIN_INIT "Error\nWindow init error"
# define ERR_IMG_INIT "Error\nSprites init error"
# define ERR_IMG_SCREEN "Error\nScreen img init error"

//* Functions' shortcut
# define MLX_IMG_WIN mlx_put_image_to_window
# define MLX_IMG_INIT mlx_xpm_file_to_image

//* Game parameters
# define WIDTH 1920
# define HEIGHT 1000
# define IMG_SIZE 512
# define CAM_ROT_SPEED 1

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
# define KEY_CTRL 65507

//* Textures
# define NO_TEXTURE 0
# define SO_TEXTURE 1
# define EA_TEXTURE 2
# define WE_TEXTURE 3
# define MINMAP_WALL 0x00333333
# define MINMAP_PLAYER 0x00FF0000
# define MINMAP_FLOOR 0x00CCCCCC
# define MINMAP_PIX_SIZE 6

//* PI
# define M_PI 3.14159265358979323846

//* game_engine
// -> cam_mouvement
void	cam_mouvemenmt(t_data *data, double old_pos_x, double old_pos_y,
			double degres);
// -> display
void	display_fc(t_data *data);
void	ft_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_mlx_pixel_get(t_data *data, int x, int y, int texture);
void	minimap_drawing(t_data *data);
// -> game_controls
int		key_press(int keycode, t_data *data);
int		mouse_move(int x, int y, t_data *data);
int		key_release(int keycode, t_data *data);
int		handle_keys(t_data *data);
// -> mlx_manegement
void	mlx_win_init(t_data *data);
int		close_mlx(t_data *data);
int		esc_press(int keycode, t_data *data);
// -> raycasting
void	game_engine(t_data *data);
// -> player_movement
void	player_move_up_down(t_data *data, double speed);
void	player_move_left_right(t_data *data, double speed);

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
int		create_rgb(int r, int g, int b);
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
// -> struct img
int		init_img(t_data *data);
void	clear_img(t_data *data);
// -> struct_map
int		init_map(t_data *data);
void	clear_map(t_data *data);
// -> struct_player
int		init_player(t_data *data);
void	clear_player(t_data *data);
// -> struct_raycast
int		init_raycast(t_data *data);
void	clear_raycast(t_data *data);

//* utils
// -> error_handler
void	error_handler(char *msg, t_data *data, int exit);
// -> raycasting_utils
int		ft_color_shadow(int color);
void	draw_texture(t_data *data);

#endif
