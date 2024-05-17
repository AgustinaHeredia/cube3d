/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:32:23 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/17 16:30:34 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_w(t_game *game, t_map *map)
{
	int	x;
	int	y;

	// printf("Presiona W\n");
	x = game->player.player_x;
	y = game->player.player_y;
	if (x - 1 >= 0 && map->map_game[x - 1][y] != '1')
	{
		map->map_game[x][y] = '0';
		map->map_game[x - 1][y] = game->player.init_pos;
		game->player.player_x--;
		game->player.up_down = 1;
		printf("Presiona W\n");
	}
}

static void	move_s(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->player.player_x;
	y = game->player.player_y;
	if (x - 1 >= 0 && map->map_game[x + 1][y] != '1')
	{
		map->map_game[x][y] = '0';
		map->map_game[x + 1][y] = game->player.init_pos;
		game->player.player_x++;
		game->player.up_down = -1;
		printf("Presiona S\n");
	}
}

static void	move_a(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->player.player_x;
	y = game->player.player_y;
	if (x - 1 >= 0 && map->map_game[x][y -1] != '1')
	{
		map->map_game[x][y] = '0';
		map->map_game[x][y -1] = game->player.init_pos;
		game->player.player_y--;
		game->player.left_right = -1;
		printf("Presiona A\n");
	}
}

static void	move_d(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->player.player_x;
	y = game->player.player_y;
	if (x - 1 >= 0 && map->map_game[x][y + 1] != '1')
	{
		map->map_game[x][y] = '0';
		map->map_game[x][y + 1] = game->player.init_pos;
		game->player.player_y++;
		game->player.left_right = 1;
		printf("Presiona D\n");
	}
}

int	press_key(t_keydata keydata, t_game *game)
{
	if (keydata.key == KEY_ESC)
	{
		printf("Chau\n");
		exit_game(game);
	}
	if (keydata.key == KEY_W)
		move_w(game, &game->map);
	if (keydata.key == KEY_A) //&& (keydata.action == KEY_PRESS))
		move_a(game, &game->map);
	if (keydata.key == KEY_S) //&& (keydata.action == KEY_PRESS))
		move_s(game, &game->map);
	if (keydata.key == KEY_D) //&& (keydata.action == KEY_PRESS))
		move_d(game, &game->map);
	if (keydata.key == KEY_LEFT)
	{
		printf("LEFT\n");
		game->player.angle -= 90;
		game->player.rote = -1;
	}
	if (keydata.key == KEY_RIGHT) //&& (keydata.action == KEY_PRESS))
		game->player.rote = 1;
	key_release(keydata, game);
	return (0);
}
