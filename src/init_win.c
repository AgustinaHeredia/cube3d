/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:24:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/14 23:01:01 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_player(t_game *game)
{
	game->playerPositionX = game->player->player_x;
	game->playerPositionY = game->player->player_y;
	game->planeX = 0;
	game->planeY = 0.66;
	game->moveSpeed = 0.05;
	game->rotSpeed = 0.05;

	if (!(game->texture = (int **)malloc(sizeof(int *) * (TEX_WIDTH * TEX_HEIGHT))))
		return ; //return (-1);
	int i = 0;
	while (i < 8)
	{
		if (!(game->texture[i] = (int *)malloc(sizeof(int) * (TEX_WIDTH * TEX_HEIGHT))))
			return ; //return (-1);
		i++;
	}
	int	j;
	j = 0;
	i = 0;
	while(i < 8)
	{
		// j = 0; // no OG
		while(j < TEX_WIDTH * TEX_HEIGHT)
		{
			game->texture[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	game_loop(void *ml)
{
	t_game	*game;

	game = ml;
	if (game->imagen)
	{
		mlx_destroy_image(game->mlx, game->imagen);
		game->imagen = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	}
	// hook(game->mlx, 0, 0); // hook the player
	// raycast(game); // cast the rays
	// mlx_put_image_to_window(game->mlx, game->win, game->imagen, 0, 0);
	return (0);
}

void	init_window(t_game *game)
{
	game->win = mlx_new_window(game->mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	game->imagen = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	path_img(game, game->map);
	init_player(game);
	mlx_key_hook(game->win, &press_key, game);
	// mlx_hook(game->win, 17, 1L << 17, &exit_game, game);
	// mlx_loop_hook(game->mlx, &game_loop, &game);
	mlx_loop(game->mlx);
}
