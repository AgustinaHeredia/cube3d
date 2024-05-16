/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:31:03 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/16 15:07:33 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_player(t_game *game, int rote)
{
	if (rote == 1)
	{
		game->player->angle += ROTATION_SPEED;
		if (game->player->angle > (2 * M_PI))
			game->player->angle -= 2 * M_PI;
	}
	else
	{
		game->player->angle -= ROTATION_SPEED;
		if (game->player->angle > (2 * M_PI))
			game->player->angle += 2 * M_PI;
	}
}

void	move_player(t_game *game, double move_x, double move_y)
{
	int	map_grid_y;
	int	map_grid_x;
	int	new_x;
	int	new_y;

	new_x = roundf(game->player->player_x + move_x);
	new_y = roundf(game->player->player_y + move_y);
	map_grid_x = (new_x / TILE_SIZE_R);
	map_grid_y = (new_y / TILE_SIZE_R);
	if (game->map->map_game[map_grid_y][map_grid_x] != '1' && \
	(game->map->map_game[map_grid_y][game->player->player_x / TILE_SIZE_R] \
	!= '1' && \
	game->map->map_game[game->player->player_y / TILE_SIZE_R][map_grid_x] \
	!= '1'))
	{
		game->player->player_x = new_x;
		game->player->player_y = new_y;
	}
}

void	key_release(t_keydata keydata, t_game *game)
{
	if (keydata.key == KEY_W && keydata.action == KEY_RELEASE)
		game->player->up_down = 0;
	else if (keydata.key == KEY_A && keydata.action == KEY_RELEASE)
		game->player->left_right = 0;
	else if (keydata.key == KEY_S && keydata.action == KEY_RELEASE)
		game->player->up_down = 0;
	else if (keydata.key == KEY_D && keydata.action == KEY_RELEASE)
		game->player->left_right = 0;
	else if (keydata.key == KEY_LEFT && keydata.action == KEY_RELEASE)
		game->player->rote = 0;
	else if (keydata.key == KEY_RIGHT && keydata.action == KEY_RELEASE)
		game->player->rote = 0;
}

void	hook_player(t_game *game, double move_x, double move_y)
{
	if (game->player->rote == 1)
		rotate_player(game, 1);
	else if (game->player->rote == -1)
		rotate_player(game, 0);
	if (game->player->up_down == 1)
	{
		move_x = sin(game->player->angle) * PLAYER_SPEED;
		move_y = cos(game->player->angle) * PLAYER_SPEED;
	}
	if (game->player->up_down == -1)
	{
		move_x = -sin(game->player->angle) * PLAYER_SPEED;
		move_y = -cos(game->player->angle) * PLAYER_SPEED;
	}
	if (game->player->left_right == 1)
	{
		move_x = -sin(game->player->angle) * PLAYER_SPEED;
		move_y = cos(game->player->angle) * PLAYER_SPEED;
	}
	if (game->player->left_right == -1)
	{
		move_x = sin(game->player->angle) * PLAYER_SPEED;
		move_y = -cos(game->player->angle) * PLAYER_SPEED;
	}
	move_player(game, move_x, move_y);
}
