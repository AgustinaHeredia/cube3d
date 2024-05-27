/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:17:59 by pquintan          #+#    #+#             */
/*   Updated: 2024/05/27 14:50:04 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void load_image(t_game *game, int *texture, char *path, t_img *img)
{
    img->img = mlx_xpm_file_to_image(game->mlx, path, &img->img_width, &img->img_height);
    if (!img->img)
    {
        fprintf(stderr, "Error: failed to load texture %s\n", path);
        exit(1);
    }
    img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);

    // Assuming the texture array size is adjusted for 600x600 images
    int img_size_bytes = img->img_width * img->img_height * sizeof(int);
    ft_memcpy(texture, img->data, img_size_bytes);
}

void	load_texture(t_game *game)
{
	t_img	img;

	game->texture[0] = malloc(MAX_TEXTURE_WIDTH * MAX_TEXTURE_HEIGHT * sizeof(int));
	if (!game->texture[0])
	{
		fprintf(stderr, "Error: failed to allocate memory for texture 0\n");
		exit(1);
	}
	load_image(game, game->texture[0], game->map.path_no, &img);

	game->texture[1] = malloc(MAX_TEXTURE_WIDTH * MAX_TEXTURE_HEIGHT * sizeof(int));
	if (!game->texture[1])
	{
		fprintf(stderr, "Error: failed to allocate memory for texture 1\n");
		exit(1);
	}
	load_image(game, game->texture[1], game->map.path_so, &img);

	game->texture[2] = malloc(MAX_TEXTURE_WIDTH * MAX_TEXTURE_HEIGHT * sizeof(int));
	if (!game->texture[2])
	{
		fprintf(stderr, "Error: failed to allocate memory for texture 2\n");
		exit(1);
	}
	load_image(game, game->texture[2], game->map.path_we, &img);

	game->texture[3] = malloc(MAX_TEXTURE_WIDTH * MAX_TEXTURE_HEIGHT * sizeof(int));
	if (!game->texture[3])
	{
		fprintf(stderr, "Error: failed to allocate memory for texture 3\n");
		exit(1);
	}
	load_image(game, game->texture[3], game->map.path_ea, &img);
}

void	image_put(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
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
			y++;
		}
		x++;
	}
}

int	get_texture(t_maths *maths)
{
	if (maths->side_texture[X] == 0)
	{
		if (maths->side_texture[Y] == 1)
			return (2);
		else
			return (3);
	}
	if (maths->side_texture[X] == 1)
		return (0);
	else
		return (1);
}
