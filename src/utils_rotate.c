/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:27:33 by agusheredia       #+#    #+#             */
/*   Updated: 2024/05/23 14:47:52 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	rotate_left(t_game *game, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ray.dir_vector_x;
	old_plane_x = game->ray.plane_x;
	game->ray.dir_vector_x = game->ray.dir_vector_x * cos(rotate_speed) \
	- game->ray.dir_vector_y * sin(rotate_speed);
	game->ray.dir_vector_y = old_dir_x * sin(rotate_speed) \
	+ game->ray.dir_vector_y * cos(rotate_speed);
	game->ray.plane_x = game->ray.plane_x * cos(rotate_speed) \
	- game->ray.plane_y * sin(rotate_speed);
	game->ray.plane_y = old_plane_x * sin(rotate_speed) \
	+ game->ray.plane_y * cos(rotate_speed);
}

static void	rotate_right(t_game *game, double rotate_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->ray.dir_vector_x;
	old_plane_x = game->ray.plane_x;
	game->ray.dir_vector_x = game->ray.dir_vector_x * cos(-rotate_speed) \
	- game->ray.dir_vector_y * sin(-rotate_speed);
	game->ray.dir_vector_y = old_dir_x * sin(-rotate_speed) \
	+ game->ray.dir_vector_y * cos(-rotate_speed);
	game->ray.plane_x = game->ray.plane_x * cos(-rotate_speed) \
	- game->ray.plane_y * sin(-rotate_speed);
	game->ray.plane_y = old_plane_x * sin(-rotate_speed) \
	+ game->ray.plane_y * cos(-rotate_speed);
}

void	handle_player_rotation(t_game *game)
{
	double	rotate_speed;

	rotate_speed = ROTATION_SPEED;
	if (game->player.rote == 1)
		rotate_left(game, rotate_speed);
	else if (game->player.rote == -1)
		rotate_right(game, rotate_speed);
}
