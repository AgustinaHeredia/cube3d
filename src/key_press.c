/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:32:23 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/15 13:14:11 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_w(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->player->player_x;
	y = game->player->player_y;
	if (x - 1 >= 0 && map->map_game[x - 1][y] != '1')
	{
		map->map_game[x][y] = '0';
		map->map_game[x - 1][y] = game->player->player_view;
		game->player->player_x--;
		game->player->up_down = 1;
	}
}

static void	move_s(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->player->player_x;
	y = game->player->player_y;
	if (x - 1 >= 0 && map->map_game[x + 1][y] != '1')
	{
		map->map_game[x][y] = '0';
		map->map_game[x + 1][y] = game->player->player_view;
		game->player->player_x++;
		game->player->up_down = -1;
	}
}

static void	move_a(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->player->player_x;
	y = game->player->player_y;
	if (x - 1 >= 0 && map->map_game[x][y -1] != '1')
	{
		map->map_game[x][y] = '0';
		map->map_game[x][y -1] = game->player->player_view;
		game->player->player_y--;
		game->player->left_right = -1;
	}
}

static void	move_d(t_game *game, t_map *map)
{
	int	x;
	int	y;

	x = game->player->player_x;
	y = game->player->player_y;
	if (x - 1 >= 0 && map->map_game[x][y + 1] != '1')
	{
		map->map_game[x][y] = '0';
		map->map_game[x][y + 1] = game->player->player_view;
		game->player->player_y++;
		game->player->left_right = 1;
	}
}

int	press_key(t_keydata keydata, t_game *game)
{
	if (keydata.key == KEY_ESC)
		exit_game(game);
	else if (keydata.key == KEY_W && keydata.action == KEY_PRESS)
		move_w(game, game->map);
	else if (keydata.key == KEY_A && keydata.action == KEY_PRESS)
		move_a(game, game->map);
	else if (keydata.key == KEY_S && keydata.action == KEY_PRESS)
		move_s(game, game->map);
	else if (keydata.key == KEY_D && keydata.action == KEY_PRESS)
		move_d(game, game->map);
	else if (keydata.key == KEY_LEFT && keydata.action == KEY_PRESS)
		game->player->rote = -1;
	else if (keydata.key == KEY_RIGHT && keydata.action == KEY_PRESS)
		game->player->rote = 1;
	key_release(keydata, game);
	return (0);
}
