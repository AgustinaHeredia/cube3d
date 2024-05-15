/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:19:57 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/15 23:33:48 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <time.h>
# include <math.h>

# define TILE_SIZE_R 16
# define FOV 60
# define ROTATION_SPEED 0.045
# define PLAYER_SPEED 2

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_LEFT	262
# define KEY_RIGHT	263

# define KEY_RELEASE 	0
# define KEY_PRESS		1
# define KEY_REPEAT 	2

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define S_WIDTH 1280
# define S_HEIGHT 720
# define TEX_W 32
# define TEX_H 32
# define X 0
# define Y 1

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

typedef struct s_pixel
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_pixel;

typedef struct s_keydata
{
	int		key;
	int		action;
}	t_keydata;

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
	double cameraX;

	double rayDirX;
	double rayDirY;

	int mapX;
	int mapY;

	double sideDistX;
	double sideDistY;

	double deltaDistX;
	double deltaDistY;

	double perpWallDist;

	int	stepX;
	int stepY;
	int hit;
	int side;
	int	*side_texture;

	long lineHeight;

	int drawStart;
	int drawEnd;

	int texNum;

	double wallX;

	int texX;
	int texY;
	
	double step;
	double texPos;

}	t_maths;

typedef struct s_player
{
	int		player_x;
	int		player_y;
	int		init_x;
	int		init_y;
	char	player_view;
	double	angle;
	int		up_down;
	int		left_right;
	int		move_x;
	int		move_y;
	int		rote;
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

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	t_ray		ray;
	t_maths		maths;
	void		*mlx;
	void		*win;
	void		*imagen;
	void		*path_n;
	void		*path_s;
	void		*path_w;
	void		*path_e;
	double		p_pos_x;
	double		p_pos_y;
	double		directionVectorX;
	double		directionVectorY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
	int			**texture;
	t_img		img;
	int			buf[S_HEIGHT][S_WIDTH];
}	t_game;

//check arg
int		check_arg_and_fd(int argc, char **argv);

//init
void	init_game(t_game *game);
void	read_file(int fd, t_game *game);
void	check_map(t_game *game);
int		all_char_valid(t_map *map);
int		check_map_resolt(t_map *map, t_player *player);
int		check_path(t_game *game);
int		check_color(t_game *game);
//game
int		exit_game(t_game *game);
int		press_key(t_keydata keydata, t_game *game);
void	init_window(t_game *game);
void	draw_map_2d(t_game *game, t_map *map);

//error files
int		ft_error(char *str);
void	error_free_exit(t_game *game, char *str);

//exit
int		exit_game(t_game *game);
int		free_map(char **tab);

//utils
char	*ft_spalloc(size_t count);
void	map_mesures(t_map *map);
void	create_map(t_map *map);
size_t	ft_wordcount(char *s, char sep);
void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color);
void	draw_square(t_pixel *data, int x, int y, int color);
int		malloc_control(t_game *game);
void	mesure_player(t_player *player, char view);

//utils debug
void	print_array(char **array);

//raycast
void	init_raycast(t_game *game);
int		raycast(t_game *game);
void	load_texture(t_game *game);
void	init_ray(t_game *game);
int		init_texture(t_game *game);

//Keys
void	rotate_player(t_game *game, int rote);
void	move_player(t_game *game, double move_x, double move_y);
void	key_release(t_keydata keydata, t_game *game);

//path
int		path_img(t_game *game, t_map *map);

#endif