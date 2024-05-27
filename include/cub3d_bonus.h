/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:19:57 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/27 11:19:41 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <time.h>
# include <math.h>

// move keys
# define TILE_SIZE_R 16 // era 16 antes
# define FOV 60
# define MOVE_SPEED 0.07
# define ROTATION_SPEED 0.025
# define PLAYER_SPEED 2 // 4 esta bien tambien
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define MOUSE_SENSITIVITY 0.005

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_RELEASE 	0
# define KEY_PRESS		1
# define KEY_REPEAT 	2

// raycast
# define S_WIDTH 1280
# define S_HEIGHT 720
# define TEX_W 32
# define TEX_H 32
# define X 0
# define Y 1
# define MARGIN 0.1

//raycast
typedef struct s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;

	int		img_width;
	int		img_height;
}	t_img;

//parseo
typedef struct s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_pixel;

typedef struct s_player
{
	int		init_x;
	int		init_y;
	double	player_x;
	double	player_y;
	char	init_pos;
	double	angle;
	int		up_down;
	int		left_right;
	int		rote;
	double	rota_speed;
	double	player_speed;
}	t_player;

typedef struct s_map
{
	char	**file;
	char	**map_game;
	int		width;
	int		height;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	*f_color;
	char	*c_color;
	int		floor;
	int		ceiling;
}	t_map;

typedef struct s_ray
{
	double		p_pos_x;
	double		p_pos_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	double		dir_vector_x;
	double		dir_vector_y;
}	t_ray;

typedef struct s_maths
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		*side_texture;
	long	line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
}	t_maths;

typedef struct s_game
{
	t_map		map;
	t_ray		ray;
	t_player	player;
	t_maths		maths;
	t_img		img;
	void		*mlx;
	void		*win;
	void		*imag;
	void		*path_n;
	void		*path_s;
	void		*path_w;
	void		*path_e;
	int			**texture;
	int			buf[S_HEIGHT][S_WIDTH];
}	t_game;

// check_arg
int		check_arg_and_fd(int argc, char **argv);

//init
void	init_game(t_game *game);
void	read_file(int fd, t_game *game);
void	check_map(t_game *game);
int		all_char_valid(char **map_game);
int		check_map_resolt(t_map *map, t_player *player);
int		check_path(t_game *game);
int		check_color(t_game *game);
void	start_plane(t_game *game);
int		one_player(t_map *map);
void	check_map_position(t_map *map);

//game
int		exit_game(t_game *game);
void	draw_map_2d(t_game *game, t_map *map);

//error files
int		ft_error(char *str);
void	error_free_exit(t_game *game, char *str);

//exit
int		exit_game(t_game *game);
int		free_map(char **tab);
void	free_texture(int **texture);

//utils
char	*ft_spalloc(size_t count);
void	map_mesures(t_map *map);
void	create_map(t_map *map);
size_t	ft_wordcount(char *s, char sep);
void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
void	draw_square(t_pixel *data, int x, int y, int color);
void	mesure_player(t_player *player, char view);
int		ft_isspace(int c);

//utils debug
void	print_array(char **array);

// raycast
int		main_raycast(t_game *game);
int		init_texture(t_game *game);
void	init_ray(t_game *game);
int		raycast(t_game *game);
int		maths_need(t_game *game, char **map);
void	prepare_draw_game(t_game *game, t_maths *maths, t_ray *ray, int x);
int		get_texture(t_maths *maths);
void	calculating_line_height(t_maths *maths, t_ray *ray);
void	perp_dist(t_maths *maths, t_ray *ray);
void	hit(t_maths *maths, char **map);
void	step_side_dist(t_game *game, t_maths *maths);

void	paint_top_bottom(t_game *game);
void	init_maths(t_maths *maths, t_ray *ray, int x);

void	image_put(t_game *game);
void	load_texture(t_game *game);
void	load_image(t_game *game, int *texture, char *path, t_img *img);
void	angle_player(t_game *game);
void	dir_player(t_game *game);

//Keys
int		press_key(int key_code, t_game *game);
void	rotate_player(t_game *game, double rote);
int		key_release(int key_code, t_game *game);
void	hook_player(t_game *game);
void	handle_player_rotation(t_game *game);
int		mouse_move(int x, int y, t_game *game);

//path
int		path_img(t_game *game, t_map *map);

#endif
