/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:24:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/09 14:49:50 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// void	upload_img(t_game *game)
// {
// 	int	img_width;
// 	int	img_height;

// 	game->img_floor = mlx_xpm_file_to_image(game->mlx,
// 			"./textures/pasto.xpm", &img_width, &img_height);
// 	// game->img_wall = mlx_xpm_file_to_image(game->mlx,
// 	// 		"./textures/arbol1.xpm", &img_width, &img_height);
// 	// game->img_player = mlx_xpm_file_to_image(game->mlx,
// 	// 		"./textures/caperucitaespalda.xpm", &img_width, &img_height);
// 	// game->img_exit = mlx_xpm_file_to_image(game->mlx,
// 	// 		"./textures/house1.xpm", &img_width, &img_height);
// }

// void	setting_map_f(t_game *game)
// {

	// int	row;
	// int	col;

	// row = 0;
	// while (row < game->height)
	// {
	// 	col = 0;
	// 	while (col < game->width)
	// 	{
	// 		if (game->map[row][col] == '1')
	// 			mlx_put_image_to_window(game->mlx, game->win,
	// 				game->img_wall, col * IMG_PX, row * IMG_PX);
	// 		else if (game->map[row][col] == 'P')
	// 			mlx_put_image_to_window(game->mlx, game->win,
	// 				game->img_player_f, col * IMG_PX, row * IMG_PX);
	// 		else if (game->map[row][col] == 'E')
	// 			mlx_put_image_to_window(game->mlx, game->win,
	// 				game->img_exit, col * IMG_PX, row * IMG_PX);
	// 		col++;
	// 	}
	// 	row++;
	// }
// }

void	paint_backgroud(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < 2)
	{
		col = 0;
		while (col < 2)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img,
				col * IMG_PX, row * IMG_PX);
			col++;
		}
		row++;
	}
}

void	init_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, 1920, 1080, "Cub3D");
	// upload_img(game);
	// paint_backgroud(game);
	// setting_map_f(game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
}
