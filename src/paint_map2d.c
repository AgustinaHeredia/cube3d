/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:13:35 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/15 11:21:27 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_square(t_pixel *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map_2d(t_game *game, t_map *map)
{
	int		x;
	int		y;
	t_pixel	img;

	(void)game;
	y = -1;
	img.img = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->map_game[y][x] == '1')
				draw_square(&img, 10 + x * 20, 10 + y * 20, map->floor);
			else if (map->map_game[y][x] == ' ')
				draw_square(&img, 10 + x * 20, 10 + y * 20, 0xFFFFFF);
			else
				draw_square(&img, 10 + x * 20, 10 + y * 20, map->ceiling);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
}

		// else if (map->map_game[y][x] == 'N' || map->map_game[y][x] == 'S'
		// 	|| map->map_game[y][x] == 'W' || map->map_game[y][x] == 'E')
		// 	draw_square(&img, 10 + x * 20, 10 + y * 20, 0x0000FF);