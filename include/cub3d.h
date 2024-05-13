/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:19:57 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/13 23:12:32 by agusheredia      ###   ########.fr       */
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
# define IMG_PX		64

# define MAP_WIDTH 24
# define MAP_HEIGHT 24
# define S_WIDTH 1280
# define S_HEIGHT 720
# define TEX_WIDTH 32
# define TEX_HEIGHT 32

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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_player
{
	int		player_x;
	int		player_y;
	char	player_view;
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
	void		*mlx;
	void		*win;
	void		*imagen;
	double		playerPositionX;
	double		playerPositionY;
	double		directionVectorX;
	double		directionVectorY;
	double		planeX;
	double		planeY;
	double		moveSpeed;
	double		rotSpeed;
	int			**texture;
	t_img		img;
	int			buf[SCREENHEIGHT][SCREENWIDTH];
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
int		press_key(int key_code, t_game *game);
void	init_window(t_game *game);
void	upload_img(t_game *game);
void	paint_backgroud(t_game *game);
void	draw_map_2d(t_game *game, t_map *map);
// void	setting_map_f(t_game *game);

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
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_square(t_data *data, int x, int y, int color);

//utils debug
void	print_array(char **array);

#endif