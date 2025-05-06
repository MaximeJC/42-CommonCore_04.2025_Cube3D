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
	struct s_img		*img;
	struct s_map		*d_map;
	struct s_player		*player;
	struct s_raycast	*ray;
}						t_data;

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
	double	pos_x;			//position x du joueur
	double	pos_y;			//position y du joueur
	double	dir_x;			//vecteur de direction (commence à -1 pour N, 1 pour S, 0 sinon)
	double	dir_y;			//vecteur de direction (commence à -1 pour W, 1 pour E, 0 sinon)
	double	plan_x;			//vecteur du plan (commence à 0.66 pour E, -0.66 pour W, 0 sinon)
	double	plan_y;			//vecteur du plan (commence à 0.66 pour N, -0.66 pour S, 0 sinon)
}			t_player;

typedef struct s_raycast
{
	double	ray_dir_x;		//calcul de direction x du rayon
	double	ray_dir_y;		//calcul de direction y du rayon
	double	camera_x;		//point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int		map_x;			//coordonée x du carré dans lequel est pos
	int		map_y;			//coordonnée y du carré dans lequel est pos
	double	side_dist_x;	//distance que le rayon parcours jusqu'au premier point d'intersection vertical (=un coté x)
	double	side_dist_y;	//distance que le rayon parcours jusqu'au premier point d'intersection horizontal (= un coté y)
	double	delta_dist_x;	//distance que rayon parcours entre chaque point d'intersection vertical
	double	delta_dist_y;	//distance que le rayon parcours entre chaque point d'intersection horizontal
	int		step_x;			//-1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int		step_y;			//-1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int		hit;			// 1 si un mur a ete touche, 0 sinon
	int		side;			// 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double	perp_wall_dist;	//distance du joueur au mur
	int		line_height;	//hauteur de la ligne a dessiner
	int		draw_start_pix;	//position de debut ou il faut dessiner
	int		draw_end_pix;	//position de fin ou il faut dessiner
	int		x;				//permet de parcourir tous les rayons
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

//* defines PI
#define M_PI 3.14159265358979323846

//* game_engine
// -> cam_mouvement
void	cam_mouvemenmt(t_data *data, double x, double y, double degres);
// -> display
void	display_once(t_data *data);
// -> game_controls
int		key_press(int keycode, t_data *data);
int		mouse_move(int x, int y, t_data *data);
// -> mlx_manegement
void	mlx_win_init(t_data *data);
int		close_mlx(t_data *data);
int		esc_press(int keycode, t_data *data);
// -> raycasting

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

#endif
