/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:17:59 by pquintan          #+#    #+#             */
/*   Updated: 2024/05/16 19:21:00 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int	x;
	int	y;

	img->img = mlx_xpm_file_to_image(game->mlx, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);

	y = 0;
	while (y < img->img_height)
	{
		x = 0;
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
	}
	// mlx_destroy_image(game->mlx, img->img); // creo que es necesario pero aqui me da problemas
}

void	load_texture(t_game *game)
{
	t_img   img;
	load_image(game, game->texture[0], game->map.path_no, &img);
	load_image(game, game->texture[1], game->map.path_so, &img);
	load_image(game, game->texture[2], game->map.path_we, &img);
	load_image(game, game->texture[3], game->map.path_ea, &img);
}

void	image_put(t_game *game)
{
	int x = 0;
	int y = 0;

	while(y < S_HEIGHT)
	{
		x = 0;
		while(x < S_WIDTH)
		{
			game->img.data[S_WIDTH * y + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	paint_top_bottom(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < S_WIDTH)
	{
		y = 0;
		while (y < S_HEIGHT)
		{
			game->buf[y][x] = game->map.floor;
			game->buf[S_HEIGHT - y - 1][x] = game->map.ceiling;
	// 		if (y < S_HEIGHT / 2)
	// 			game->buf[y][x] = game->map->ceiling;
	// 		else
	// 			game->buf[y][x] = game->map->floor;
			y++;
		}
		x++;
	}
}

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

void	step_side_dist(t_game *game, t_maths *maths) // change if for more compression
{
	if (maths->ray_dir_x < 0)
	{
		maths->step_x = -1;
		maths->side_dist_x = (game->ray.p_pos_x - maths->map_x) * maths->delta_dist_x;
	}
	else
	{
		maths->step_x = 1;
		maths->side_dist_x = (maths->map_x + 1.0 - game->ray.p_pos_x) * maths->delta_dist_x;
	}
	if (maths->ray_dir_y < 0)
	{
		maths->step_y = -1;
		maths->side_dist_y = (game->ray.p_pos_y - maths->map_y) * maths->delta_dist_y;
	}
	else
	{
		maths->step_y = 1;
		maths->side_dist_y = (maths->map_y + 1.0 - game->ray.p_pos_y) * maths->delta_dist_y;
	}
}

void hit(t_maths *maths, char **map)
{
	while (maths->hit == 0)
	{
		if (maths->side_dist_x < maths->side_dist_y)
		{
			maths->side_dist_x += maths->delta_dist_x;
			maths->map_x += maths->step_x;
			maths->side = 0;
			// maths->side_texture[X] = 1;
			// maths->side_texture[Y] = 0;
			// if (maths->step_x < 0)
			// 	maths->side_texture[X] = -1;
		}
		else
		{
			maths->side_dist_y += maths->delta_dist_y;
			maths->map_y += maths->step_y;
			maths->side = 1;
			// maths->side_texture[X] = 0;
			// maths->side_texture[Y] = 1;
			// if (maths->step_y < 0)
			// 	maths->side_texture[Y] = -1;
		}
		if (map[maths->map_x][maths->map_y] != '0')
			maths->hit = 1;
	}
}

void	perp_dist(t_maths *maths, t_ray *ray)
{
	if (maths->side == 0)
		maths->perp_wall_dist = (maths->map_x - ray->p_pos_x + (1 - maths->step_x) / 2) / maths->ray_dir_x;
	else
		maths->perp_wall_dist = (maths->map_y - ray->p_pos_y + (1 - maths->step_y) / 2) / maths->ray_dir_y;
}

void calculating_line_height(t_maths *maths, t_ray *ray, char **map)
{
	// calculate height of line to draw on screen
	maths->line_height = 0;
	// printf("maths->perp_wall_dist: %f\n", maths->perp_wall_dist);
	maths->line_height = (int)(S_HEIGHT / maths->perp_wall_dist);

	// calculate lowest and highest pixel to fill in current stripe
	maths->draw_start = -maths->line_height / 2 + S_HEIGHT / 2;
	if (maths->draw_start < 0)
		maths->draw_start = 0;
	
	// calculate highest pixel to fill in current stripe
	maths->draw_end = maths->line_height / 2 + S_HEIGHT / 2;
	if (maths->draw_end >= S_HEIGHT)
		maths->draw_end = S_HEIGHT - 1;

	maths->tex_num = map[maths->map_x][maths->map_y] - '0';
	
	if (maths->side == 0)
		maths->wall_x = ray->p_pos_y + maths->perp_wall_dist * maths->ray_dir_y;
	else
		maths->wall_x = ray->p_pos_x + maths->perp_wall_dist * maths->ray_dir_x;
	maths->wall_x -= floor(maths->wall_x); // truncates the decimal part
	// 90 180 270 360
}

int	get_texture(t_game *game, t_maths *maths)
{
	// if (maths->side_texture[X] == 0)
	if (maths->side == 0)
	{
		if (maths->side_texture[Y] == 1)
			return (game->texture[0][TEX_H * maths->tex_y + maths->tex_x]);
		else
			return (game->texture[1][TEX_H * maths->tex_y + maths->tex_x]);
	}
	else
	{
		// if (maths->side_texture[Y] == 1)
		if (maths->side == 1)
			return (game->texture[2][TEX_H * maths->tex_y + maths->tex_x]);
		else
			return (game->texture[3][TEX_H * maths->tex_y + maths->tex_x]);
	}
}

void	draw(t_game *game, t_maths *maths, t_ray *ray, int x, char **map)
{
	calculating_line_height(maths, ray, map);

	maths->tex_x = (int)(maths->wall_x * (double)TEX_W);
	if (maths->side == 0 && maths->ray_dir_x > 0)
		maths->tex_x = TEX_W - maths->tex_x - 1;
	if (maths->side == 1 && maths->ray_dir_y < 0)
		maths->tex_x = TEX_W - maths->tex_x - 1;

	maths->step = 1.0 * TEX_H / maths->line_height;
	maths->tex_pos = (maths->draw_start - S_HEIGHT / 2 + maths->line_height / 2) * maths->step;

	int y = maths->draw_start;
	while (y < maths->draw_end)
	{
		maths->tex_y = (int)maths->tex_pos & (TEX_H - 1);
		maths->tex_pos += maths->step;
		int texture;
		// texture = get_texture(game, &game->maths);
		texture = game->texture[maths->tex_num][TEX_H * maths->tex_y + maths->tex_x];
		// if (maths->side == 1)
		// 	texture = (texture >> 1) & 8355711; // no needed, used for shading lateral walls
		game->buf[y][x] = texture;
		y++;
	}
}

void	init_var(t_maths *maths)
{
	maths->camera_x = 0;
	maths->ray_dir_x = 0;
	maths->ray_dir_y = 0;
	maths->map_x = 0;
	maths->map_y = 0;
	maths->side_dist_x = 0;
	maths->side_dist_y = 0;
	maths->delta_dist_x = 0;
	maths->delta_dist_y = 0;
	maths->perp_wall_dist = 0;
	maths->step_x = 0;
	maths->step_y = 0;
	maths->hit = 0;
	maths->side = 0;
	maths->line_height = 0;
	maths->draw_start = 0;
	maths->draw_end = 0;
	maths->tex_num = 0;
	maths->wall_x = 0;
	maths->tex_x = 0;
	maths->tex_y = 0;
	maths->step = 0;
	maths->tex_pos = 0;
}

int	maths_need(t_game *game, char** map)
{
	paint_top_bottom(game);
	int x;

	x = 0;
	while (x < S_WIDTH)
	{
		init_var(&game->maths);
		init_maths(&game->maths, &game->ray, x);
		step_side_dist(game, &game->maths);
		hit(&game->maths, map);
		perp_dist(&game->maths, &game->ray);
		draw(game, &game->maths, &game->ray, x, map); // provisional
		x++;
	}
	return (0);
}

int	raycast(t_game *game)
{
	// if (game->img.img)
	// 	mlx_destroy_image(game->mlx, game->img.img);
	init_ray(game);
	if (init_texture(game) == -1)
		return (-1);
	load_texture(game);
	hook_player(game, 0, 0);
	maths_need(game, game->map.map_game);
	image_put(game);
	return (0);
}

void	init_ray(t_game *game)
{
	game->ray.p_pos_x = game->player.player_x;
	game->ray.p_pos_y = game->player.player_y;
	game->ray.plane_x = 0;
	game->ray.plane_y = 0.66; // FOV
	game->ray.move_speed = 0.05; 
	game->ray.rot_speed = 0.05;
	// angle_player(game); // iniciado en el parseo
	dir_player(game);
}

int	init_texture(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(game->texture = (int **)malloc(sizeof(int *) * (TEX_W * TEX_H))))
		return (-1);
	while (i < 8)
	{
		if (!(game->texture[i] = (int *)malloc(sizeof(int) * (TEX_W * TEX_H))))
			return (-1);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		while (j < TEX_W * TEX_H)
		{
			game->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int	init_raycast(t_game *game)
{
	game->win = mlx_new_window(game->mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	game->img.img = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
	if (path_img(game, &game->map) == -1)
		return (ft_error("Error. Path is not valid\n"));
	// init path .xpm en void
	mlx_key_hook(game->win, &press_key, game); // evaluar cual de las dos es la correcta
	mlx_loop_hook(game->mlx, &raycast, game);
	// draw_map_2d(game, &game->map); // minimapa
	// mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &key_release, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
	return (0);
}
