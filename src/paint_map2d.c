/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:13:35 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/10 14:04:30 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_map_2d(t_game *game, t_map *map)
{
	int		x;
	int		y;
	t_data	img;

	y = 0;
	(void)map;
	img.img = mlx_new_image(game->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map_game[y][x] == '1')
				my_mlx_pixel_put(&img, 10 + x * 20, 10 + y * 20, 0x00FF00);
			else if (map->map_game[y][x] == '0')
				my_mlx_pixel_put(&img, 10 + x * 20, 10 + y * 20, 0xFF0000);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
}
