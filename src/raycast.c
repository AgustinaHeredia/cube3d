/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:24:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/14 22:55:32 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <time.h> // raycast
#include <math.h> // raycast

void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int     x;
	int     y;

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
	t_img	img;

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

int	maths_need(t_game *game, char** worldMap)
{
	int	x = 0;
	int	y;

	while (x < S_WIDTH)
	{
		y = 0;
		while (y < S_WIDTH)
		{
			game->buf[y][x] = 0xc2b280;
			game->buf[S_HEIGHT - y - 1][x] = 0x2add8e6;
			y++;
		}
		x++;
	}
	x = 0;
	while (x < S_WIDTH)
	{
		double cameraX;
		cameraX = 2 * x / (double)S_WIDTH - 1;

		double rayDirX;
		double rayDirY;

		rayDirX = game->directionVectorX + game->planeX * cameraX;
		rayDirY = game->directionVectorY + game->planeY * cameraX;

		int mapX;
		int mapY;

		mapX = (int)game->playerPositionX;
		mapY = (int)game->playerPositionY;

		double sideDistX;
		double sideDistY;

		double deltaDistX;
		double deltaDistY;
		
		deltaDistX = fabs(1 / rayDirX);	
		deltaDistY = fabs(1 / rayDirY);

		double perpWallDist;

		int stepX;
		int stepY;
		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->playerPositionX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->playerPositionX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->playerPositionY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->playerPositionY) * deltaDistY;
		}

		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] != '0')
				hit = 1;
		}

		if (side == 0)
			perpWallDist = (mapX - game->playerPositionX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - game->playerPositionY + (1 - stepY) / 2) / rayDirY;

		int lineHeight;
		lineHeight = (int)(S_HEIGHT / perpWallDist);

		int drawStart;
		int drawEnd;

		drawStart = -lineHeight / 2 + S_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;

		drawEnd = lineHeight / 2 + S_HEIGHT / 2;
		if (drawEnd >= S_HEIGHT)
			drawEnd = S_HEIGHT - 1;

		int texNum;
		// char texNum;
		texNum = worldMap[mapX][mapY] - '0';

		double wallX;

		if (side == 0)
			wallX = game->playerPositionY + perpWallDist * rayDirY;
		else
			wallX = game->playerPositionX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int texX;
		texX = (int)(wallX * (double)TEX_WIDTH);
		if (side == 0 && rayDirX > 0)
			texX = TEX_WIDTH - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = TEX_WIDTH - texX - 1;
		
		double step;
		double texPos;

		step = 1.0 * TEX_HEIGHT / lineHeight;
		texPos = (drawStart - S_HEIGHT / 2 + lineHeight / 2) * step;

		y = drawStart;
		while (y < drawEnd)
		{
			int texY;
			texY = (int)texPos & (TEX_HEIGHT - 1);
			texPos += step;
			int color;
			color = game->texture[texNum][TEX_HEIGHT * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711; // no needed, used for shading lateral walls
			game->buf[y][x] = color;
			y++;
		}
		x++;
	}
	return (0);
}

int	raycast(t_game *game)
{
	// maths_need(game);
	// maths_need(game, game->map->map_game);
	image_put(game);

	return (0);
}
