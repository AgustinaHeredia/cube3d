/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:17:59 by pquintan          #+#    #+#             */
/*   Updated: 2024/05/15 23:34:22 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <time.h> // raycast
#include <math.h> // raycast

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
	load_image(game, game->texture[0], game->map->path_no, &img);
	load_image(game, game->texture[1], game->map->path_so, &img);
	load_image(game, game->texture[2], game->map->path_we, &img);
	load_image(game, game->texture[3], game->map->path_ea, &img);
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
			game->buf[y][x] = game->map->floor;
			game->buf[S_HEIGHT - y - 1][x] = game->map->ceiling;
	// 		if (y < screenHeight / 2)
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
	maths->cameraX = 2 * x / (double)S_WIDTH - 1;

	maths->rayDirX = ray->dir_vector_x + ray->plane_x * maths->cameraX;
	maths->rayDirY = ray->dir_vector_y + ray->plane_y * maths->cameraX;

	maths->mapX = (int)ray->p_pos_x;
	maths->mapY = (int)ray->p_pos_y;

	maths->deltaDistX = fabs(1 / maths->rayDirX);	
	maths->deltaDistY = fabs(1 / maths->rayDirY);
}

void	step_side_dist(t_game *game, t_maths *maths) // change if for more compression
{
	if (maths->rayDirX < 0)
	{
		maths->stepX = -1;
		maths->sideDistX = (game->ray.p_pos_x - maths->mapX) * maths->deltaDistX;
	}
	else
	{
		maths->stepX = 1;
		maths->sideDistX = (maths->mapX + 1.0 - game->ray.p_pos_x) * maths->deltaDistX;
	}
	if (maths->rayDirY < 0)
	{
		maths->stepY = -1;
		maths->sideDistY = (game->ray.p_pos_y - maths->mapY) * maths->deltaDistY;
	}
	else
	{
		maths->stepY = 1;
		maths->sideDistY = (maths->mapY + 1.0 - game->ray.p_pos_y) * maths->deltaDistY;
	}
}

void hit(t_maths *maths, char **map)
{
	while (maths->hit == 0)
	{
		if (maths->sideDistX < maths->sideDistY)
		{
			maths->sideDistX += maths->deltaDistX;
			maths->mapX += maths->stepX;
			maths->side = 0;
			// maths->side_texture[X] = 1;
			// maths->side_texture[Y] = 0;
			// if (maths->stepX < 0)
			// 	maths->side_texture[X] = -1;
		}
		else
		{
			maths->sideDistY += maths->deltaDistY;
			maths->mapY += maths->stepY;
			maths->side = 1;
			// maths->side_texture[X] = 0;
			// maths->side_texture[Y] = 1;
			// if (maths->stepY < 0)
			// 	maths->side_texture[Y] = -1;
		}
		if (map[maths->mapX][maths->mapY] != '0')
			maths->hit = 1;
	}
}

void	perp_dist(t_maths *maths, t_ray *ray)
{
	if (maths->side == 0)
		maths->perpWallDist = (maths->mapX - ray->p_pos_x + (1 - maths->stepX) / 2) / maths->rayDirX;
	else
		maths->perpWallDist = (maths->mapY - ray->p_pos_y + (1 - maths->stepY) / 2) / maths->rayDirY;
}

void calculating_line_height(t_maths *maths, t_ray *ray, char **map)
{
	// calculate height of line to draw on screen
	maths->lineHeight = 0;
	maths->lineHeight = (int)(S_HEIGHT / maths->perpWallDist);

	// calculate lowest and highest pixel to fill in current stripe
	maths->drawStart = -maths->lineHeight / 2 + S_HEIGHT / 2;
	if (maths->drawStart < 0)
		maths->drawStart = 0;
	
	// calculate highest pixel to fill in current stripe
	maths->drawEnd = maths->lineHeight / 2 + S_HEIGHT / 2;
	if (maths->drawEnd >= S_HEIGHT)
		maths->drawEnd = S_HEIGHT - 1;

	maths->texNum = map[maths->mapX][maths->mapY] - '0';
	
	if (maths->side == 0)
		maths->wallX = ray->p_pos_y + maths->perpWallDist * maths->rayDirY;
	else
		maths->wallX = ray->p_pos_x + maths->perpWallDist * maths->rayDirX;
	maths->wallX -= floor(maths->wallX); // truncates the decimal part
	// 90 180 270 360
}

int	get_texture(t_game *game, t_maths *maths)
{
	// if (maths->side_texture[X] == 0)
	if (maths->side == 0)
	{
		if (maths->side_texture[Y] == 1)
			return (game->texture[0][TEX_H * maths->texY + maths->texX]);
		else
			return (game->texture[1][TEX_H * maths->texY + maths->texX]);
	}
	else
	{
		// if (maths->side_texture[Y] == 1)
		if (maths->side == 1)
			return (game->texture[2][TEX_H * maths->texY + maths->texX]);
		else
			return (game->texture[3][TEX_H * maths->texY + maths->texX]);
	}
}

void	draw(t_game *game, t_maths *maths, t_ray *ray, int x, char **map)
{
	calculating_line_height(maths, ray, map);

	maths->texX = (int)(maths->wallX * (double)TEX_W);
	if (maths->side == 0 && maths->rayDirX > 0)
		maths->texX = TEX_W - maths->texX - 1;
	if (maths->side == 1 && maths->rayDirY < 0)
		maths->texX = TEX_W - maths->texX - 1;

	maths->step = 1.0 * TEX_H / maths->lineHeight;
	maths->texPos = (maths->drawStart - S_HEIGHT / 2 + maths->lineHeight / 2) * maths->step;

	int y = maths->drawStart;
	while (y < maths->drawEnd)
	{
		maths->texY = (int)maths->texPos & (TEX_H - 1);
		maths->texPos += maths->step;
		int texture;
		// texture = get_texture(game, &game->maths);
		texture = game->texture[maths->texNum][TEX_H * maths->texY + maths->texX];
		// if (maths->side == 1)
		// 	texture = (texture >> 1) & 8355711; // no needed, used for shading lateral walls
		game->buf[y][x] = texture;
		y++;
	}
}

void	init_var(t_maths *maths)
{
	maths->cameraX = 0;
	maths->rayDirX = 0;
	maths->rayDirY = 0;
	maths->mapX = 0;
	maths->mapY = 0;
	maths->sideDistX = 0;
	maths->sideDistY = 0;
	maths->deltaDistX = 0;
	maths->deltaDistY = 0;
	maths->perpWallDist = 0;
	maths->stepX = 0;
	maths->stepY = 0;
	maths->hit = 0;
	maths->side = 0;
	maths->lineHeight = 0;
	maths->drawStart = 0;
	maths->drawEnd = 0;
	maths->texNum = 0;
	maths->wallX = 0;
	maths->texX = 0;
	maths->texY = 0;
	maths->step = 0;
	maths->texPos = 0;
}

int	maths_need(t_game *game, char** map)
{
	paint_top_bottom(game);
	int x;

	x = 0;
	while(x < S_WIDTH)
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
	init_ray(game);
	if (init_texture(game) == -1)
		return (-1);
	load_texture(game);
	maths_need(game, game->map->map_game);
	image_put(game);
	return (0);
}

void	init_ray(t_game *game)
{
	game->ray.p_pos_x = game->player->init_x;
	game->ray.p_pos_y = game->player->init_y;
	game->ray.plane_x = 0;
	game->ray.plane_y = 0.66; // FOV
	game->ray.move_speed = 0.05; 
	game->ray.rot_speed = 0.05;
	// angle_player(game);
	// dir_player(game);
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

void	init_raycast(t_game *game)
{
	game->win = mlx_new_window(game->mlx, S_WIDTH, S_HEIGHT, "raycasting");
	game->img.img = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);

	mlx_loop_hook(game->mlx, &raycast, game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
}
