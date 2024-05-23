/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 01:27:33 by agusheredia       #+#    #+#             */
/*   Updated: 2024/05/22 19:11:07 by pquintan         ###   ########.fr       */
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

// static void	rot(t_game *game, double rote)
// {
// 	double	old_dir_x;
// 	double	old_plane_x;
// 	double	cos_angle;
// 	double	sin_angle;

// 	cos_angle = cos(rote);
// 	sin_angle = sin(rote);
// 	old_dir_x = game->ray.dir_vector_x;
// 	game->ray.dir_vector_x = game->ray.dir_vector_x * cos_angle - game->ray.dir_vector_y * sin_angle;
// 	game->ray.dir_vector_y = old_dir_x * sin_angle + game->ray.dir_vector_y * cos_angle;

// 	old_plane_x = game->ray.plane_x;
// 	game->ray.plane_x = game->ray.plane_x * cos_angle - game->ray.plane_y * sin_angle;
// 	game->ray.plane_y = old_plane_x * sin_angle + game->ray.plane_y * cos_angle;
// }

// void	rotate_player(t_game *game, int rote)
// {
// 	printf("Angle Antes: %f\n", game->player.angle);
// 	if (rote == 1)
// 		game->player.angle += ROTATION_SPEED;
// 	else
// 		game->player.angle -= ROTATION_SPEED;
// 	game->player.angle = fmod(game->player.angle, 2 * M_PI);
// 	if (game->player.angle < 0)
// 		game->player.angle += 2 * M_PI;
// 	rot(game, game->player.angle);
// 	printf("Angle Despues: %f\n", game->player.angle);
// }

void	handle_player_rotation(t_game *game)
{
	double	rotate_speed;

	rotate_speed = ROTATION_SPEED;
	// if (game->player.mouse_rotate)
	// 	rotate_speed *= 2 * game->player.rotate_speed;
	
	if (game->player.rote == 1)
		// rotate_player(game, 1);
		rotate_left(game, rotate_speed);
	else if (game->player.rote == -1)
		// rotate_player(game, -1);
		rotate_right(game, rotate_speed);
}
