/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:24:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/15 13:18:22 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

// int	maths_need(t_game *game, char** worldMap)
// {}

int	raycast(t_game *game)
{
	(void)game;
	// maths_need(game);
	// maths_need(game, game->map->map_game);
	// image_put(game);
	printf("Holis\n");
	return (0);
}
