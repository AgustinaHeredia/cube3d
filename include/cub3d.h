/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:19:57 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/02 17:52:23 by agheredi         ###   ########.fr       */
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

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define IMG_PX		64

typedef struct s_player
{
	int		player_x;
	int		player_y;
}	t_player;

typedef struct s_map
{
	char	**file;
	char	**map_game;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	t_map		*map;
	t_player	*player;
	void		*mlx;
	void		*win;
	void		*img_floor;
}	t_game;

//check arg
int		check_arg_and_fd(int argc, char **argv);

//init
void	init_game(t_game *game);
void	read_file(int fd, t_game *game);
void	check_map(t_game *game);
int		all_char_valid(t_map *map);

//game
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);
void	init_window(t_game *game);
void	upload_img(t_game *game);
void	paint_backgroud(t_game *game);
// void	setting_map_f(t_game *game);

//error files
int		ft_error(char *str);
void	error_free_exit(t_game *game, char *str);

//exit
int		exit_game(t_game *game);
void	free_map(char **tab);

#endif