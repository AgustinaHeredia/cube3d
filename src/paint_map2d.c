/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_map2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:13:35 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/22 14:45:42 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	my_mlx_pixel_put(t_pixel *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_square(t_pixel *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == 0 || i == size - 1 || j == 0 || j == size -1)
				my_mlx_pixel_put(data, x + i, y + j, 0x595A5D);
			else
				my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_player(t_pixel *data, t_game *game, int cell_size)
{
	int	i;
	int	j;
	int	player_size;

	player_size = cell_size / 3;
	i = 0;
	while (i < player_size)
	{
		j = 0;
		while (j < player_size)
		{
			my_mlx_pixel_put(data, 10 + game->ray.p_pos_y * cell_size + i, \
			10 + game->ray.p_pos_x * cell_size + j, 0x2ECC71);
			// draw_direction_line(data, game, cell_size);
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
	x = 0;
	img.img = mlx_new_image(game->mlx, map->width * 15, map->height * 15);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	while (x < map->height)
	{
		y = 0;
		while (y < map->width)
		{
			if (map->map_game[x][y] && map->map_game[x][y] == '1')
				draw_square(&img, y * 15, x * 15, 15, 0xC0E3DC);
			else if (map->map_game[x][y] == ' ')
				draw_square(&img, y * 15, x * 15, 15, 0xFFFFFF);
			else
				draw_square(&img, y * 15, x * 15, 15, 0x5D0D71);
			y++;
		}
		draw_player(&img, game, 15);
		x++;
	}
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
}
