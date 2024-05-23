/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:17:59 by pquintan          #+#    #+#             */
/*   Updated: 2024/05/23 14:32:13 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	maths_need(t_game *game, char **map)
{
	int	x;

	x = 0;
	while (x < S_WIDTH)
	{
		init_maths(&game->maths, &game->ray, x);
		step_side_dist(game, &game->maths);
		hit(&game->maths, map);
		perp_dist(&game->maths);
		prepare_draw_game (game, &game->maths, &game->ray, x);
		x++;
	}
	return (0);
}

void	init_ray(t_game *game)
{
	game->ray.p_pos_x = game->player.player_x;
	game->ray.p_pos_y = game->player.player_y;
	game->ray.move_speed = 0.05;
	game->ray.rot_speed = 0.05;
}

int	init_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	game->texture = (int **)malloc(sizeof(int *) * (TEX_W * TEX_H));
	if (!game->texture)
		return (-1);
	while (i < 8)
	{
		game->texture[i] = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
		if (!game->texture[i])
			return (-1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		while (j++ < TEX_W * TEX_H)
			game->texture[i][j] = 0;
		i++;
	}
	return (0);
}
