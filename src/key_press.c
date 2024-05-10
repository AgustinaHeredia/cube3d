/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:32:23 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/10 10:38:27 by agheredi         ###   ########.fr       */
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
		// paint_backgroud(game);
		// setting_map_b(game);
	}
}

void	move_a(t_game *game, t_map *map)
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
		// paint_backgroud(game);
		// setting_map_l(game);
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
		// paint_backgroud(game);
		// setting_map_r(game);
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
		// paint_backgroud(game);
		// setting_map_f(game);
	}
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_W)
		move_w(game, game->map);
	if (key_code == KEY_A)
		move_a(game, game->map);
	if (key_code == KEY_S)
		move_s(game, game->map);
	if (key_code == KEY_D)
		move_d(game, game->map);
	return (0);
}
