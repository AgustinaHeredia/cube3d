/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:31:03 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/22 19:10:09 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_forward(t_game *game)
{
	double new_x;
	double new_y;

	new_x = game->player.player_x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.player_y + game->player.dir_y * MOVE_SPEED;
	if (game->map.map_game[(int)(new_x + MARGIN)][(int)(game->player.player_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(new_x - MARGIN)][(int)(game->player.player_y - MARGIN)] != '1')
	{
		game->player.player_x = new_x;
	}
	if (game->map.map_game[(int)(game->player.player_x + MARGIN)][(int)(new_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(game->player.player_x - MARGIN)][(int)(new_y - MARGIN)] != '1')
	{
		game->player.player_y = new_y;
	}
}

static void	move_backward(t_game *game)
{
	double new_x;
	double new_y;

	new_x = game->player.player_x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.player_y - game->player.dir_y * MOVE_SPEED;
	if (game->map.map_game[(int)(new_x + MARGIN)][(int)(game->player.player_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(new_x - MARGIN)][(int)(game->player.player_y - MARGIN)] != '1')
	{
		game->player.player_x = new_x;
	}
	if (game->map.map_game[(int)(game->player.player_x + MARGIN)][(int)(new_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(game->player.player_x - MARGIN)][(int)(new_y - MARGIN)] != '1')
	{
		game->player.player_y = new_y;
	}
}

static void	move_left(t_game *game)
{
	double new_x;
	double new_y;

	new_x = game->player.player_x - game->player.dir_y * MOVE_SPEED;
	new_y = game->player.player_y + game->player.dir_x * MOVE_SPEED;
	if (game->map.map_game[(int)(new_x + MARGIN)][(int)(game->player.player_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(new_x - MARGIN)][(int)(game->player.player_y - MARGIN)] != '1')
	{
		game->player.player_x = new_x;
	}
	if (game->map.map_game[(int)(game->player.player_x + MARGIN)][(int)(new_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(game->player.player_x - MARGIN)][(int)(new_y - MARGIN)] != '1')
	{
		game->player.player_y = new_y;
	}
}

static void	move_right(t_game *game)
{
	double new_x;
	double new_y;

	new_x = game->player.player_x + game->player.dir_y * MOVE_SPEED;
	new_y = game->player.player_y - game->player.dir_x * MOVE_SPEED;
	if (game->map.map_game[(int)(new_x + MARGIN)][(int)(game->player.player_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(new_x - MARGIN)][(int)(game->player.player_y - MARGIN)] != '1')
	{
		game->player.player_x = new_x;
	}
	if (game->map.map_game[(int)(game->player.player_x + MARGIN)][(int)(new_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(game->player.player_x - MARGIN)][(int)(new_y - MARGIN)] != '1')
	{
		game->player.player_y = new_y;
	}
}

void hook_player(t_game *game)
{
	if (game->player.rote == 1)
	{
        printf("PRESS Right\n");
		handle_player_rotation(game);
	}
	else if (game->player.rote == -1)
	{
        printf("PRESS Left\n");
		handle_player_rotation(game);
	}
	else if (game->player.up_down == 1)
	{
        printf("PRESS W\n");
		move_forward(game);
	}
	else if (game->player.up_down == -1)
	{
        printf("PRESS S\n");
		move_backward(game);
	}
	else if (game->player.left_right == 1)
	{
        printf("PRESS D\n");
		move_right(game);
	}
	else if (game->player.left_right == -1)
	{
        printf("PRESS A\n");
		move_left(game);
	}
}
