/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:31:03 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/23 17:16:47 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x + game->ray.dir_vector_x * MOVE_SPEED;
	new_y = game->player.player_y + game->ray.dir_vector_y * MOVE_SPEED;
	if (game->map.map_game[(int)(new_x + MARGIN)] \
	[(int)(game->player.player_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(new_x - MARGIN)] \
		[(int)(game->player.player_y - MARGIN)] != '1')
	{
		game->player.player_x = new_x;
	}
	if (game->map.map_game[(int)(game->player.player_x + MARGIN)] \
	[(int)(new_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(game->player.player_x - MARGIN)] \
		[(int)(new_y - MARGIN)] != '1')
	{
		game->player.player_y = new_y;
	}
}

static void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x - game->ray.dir_vector_x * MOVE_SPEED;
	new_y = game->player.player_y - game->ray.dir_vector_y * MOVE_SPEED;
	if (game->map.map_game[(int)(new_x + MARGIN)] \
	[(int)(game->player.player_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(new_x - MARGIN)] \
		[(int)(game->player.player_y - MARGIN)] != '1')
	{
		game->player.player_x = new_x;
	}
	if (game->map.map_game[(int)(game->player.player_x + MARGIN)] \
	[(int)(new_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(game->player.player_x - MARGIN)] \
		[(int)(new_y - MARGIN)] != '1')
	{
		game->player.player_y = new_y;
	}
}

static void	move_left(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x - game->ray.dir_vector_y * MOVE_SPEED;
	new_y = game->player.player_y + game->ray.dir_vector_x * MOVE_SPEED;
	if (game->map.map_game[(int)(new_x + MARGIN)] \
	[(int)(game->player.player_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(new_x - MARGIN)] \
		[(int)(game->player.player_y - MARGIN)] != '1')
	{
		game->player.player_x = new_x;
	}
	if (game->map.map_game[(int)(game->player.player_x + MARGIN)] \
	[(int)(new_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(game->player.player_x - MARGIN)] \
		[(int)(new_y - MARGIN)] != '1')
	{
		game->player.player_y = new_y;
	}
}

static void	move_right(t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.player_x + game->ray.dir_vector_y * MOVE_SPEED;
	new_y = game->player.player_y - game->ray.dir_vector_x * MOVE_SPEED;
	if (game->map.map_game[(int)(new_x + MARGIN)] \
	[(int)(game->player.player_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(new_x - MARGIN)] \
		[(int)(game->player.player_y - MARGIN)] != '1')
	{
		game->player.player_x = new_x;
	}
	if (game->map.map_game[(int)(game->player.player_x + MARGIN)] \
	[(int)(new_y + MARGIN)] != '1' &&
		game->map.map_game[(int)(game->player.player_x - MARGIN)] \
		[(int)(new_y - MARGIN)] != '1')
	{
		game->player.player_y = new_y;
	}
}

void	hook_player(t_game *game)
{
	if (game->player.rote == 1)
	{
		handle_player_rotation(game);
	}
	else if (game->player.rote == -1)
	{
		handle_player_rotation(game);
	}
	else if (game->player.up_down == 1)
	{
		move_forward(game);
	}
	else if (game->player.up_down == -1)
	{
		move_backward(game);
	}
	else if (game->player.left_right == 1)
	{
		move_right(game);
	}
	else if (game->player.left_right == -1)
	{
		move_left(game);
	}
}
