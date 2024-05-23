/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:17:59 by pquintan          #+#    #+#             */
/*   Updated: 2024/05/23 14:32:51 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_maths(t_maths *maths, t_ray *ray, int x)
{
	maths->camera_x = 2 * x / (double)S_WIDTH - 1;
	maths->ray_dir_x = ray->dir_vector_x + ray->plane_x * maths->camera_x;
	maths->ray_dir_y = ray->dir_vector_y + ray->plane_y * maths->camera_x;
	maths->map_x = (int)ray->p_pos_x;
	maths->map_y = (int)ray->p_pos_y;
	maths->delta_dist_x = fabs(1 / maths->ray_dir_x);
	maths->delta_dist_y = fabs(1 / maths->ray_dir_y);
}

void	step_side_dist(t_game *game, t_maths *maths)
{
	if (maths->ray_dir_x < 0)
	{
		maths->step_x = -1;
		maths->side_dist_x = (game->ray.p_pos_x - maths->map_x) \
		* maths->delta_dist_x;
	}
	else
	{
		maths->step_x = 1;
		maths->side_dist_x = (maths->map_x + 1.0 - game->ray.p_pos_x) \
		* maths->delta_dist_x;
	}
	if (maths->ray_dir_y < 0)
	{
		maths->step_y = -1;
		maths->side_dist_y = (game->ray.p_pos_y - maths->map_y) \
		* maths->delta_dist_y;
	}
	else
	{
		maths->step_y = 1;
		maths->side_dist_y = (maths->map_y + 1.0 - game->ray.p_pos_y) \
		* maths->delta_dist_y;
	}
}

void	hit(t_maths *maths, char **map)
{
	while (1)
	{
		if (maths->side_dist_x < maths->side_dist_y)
		{
			maths->side_dist_x += maths->delta_dist_x;
			maths->map_x += maths->step_x;
			maths->side = 0;
			maths->side_texture[X] = 1;
			maths->side_texture[Y] = 0;
			if (maths->step_x < 0)
				maths->side_texture[X] = -1;
		}
		else
		{
			maths->side_dist_y += maths->delta_dist_y;
			maths->map_y += maths->step_y;
			maths->side = 1;
			maths->side_texture[X] = 0;
			maths->side_texture[Y] = 1;
			if (maths->step_y < 0)
				maths->side_texture[Y] = -1;
		}
		if (map[maths->map_x][maths->map_y] == '1')
			break ;
	}
}

void	perp_dist(t_maths *maths)
{
	if (maths->side_texture[X] != 0)
		maths->perp_wall_dist = (maths->side_dist_x - maths->delta_dist_x);
	else
		maths->perp_wall_dist = (maths->side_dist_y - maths->delta_dist_y);
}
