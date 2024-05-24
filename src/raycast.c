/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:17:59 by pquintan          #+#    #+#             */
/*   Updated: 2024/05/24 10:27:17 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	calculating_line_height(t_maths *maths, t_ray *ray)
{
	maths->line_height = (long)(S_HEIGHT / maths->perp_wall_dist);
	maths->draw_start = -maths->line_height / 2 + S_HEIGHT / 2;
	if (maths->draw_start < 0)
		maths->draw_start = 0;
	maths->draw_end = maths->line_height / 2 + S_HEIGHT / 2;
	if (maths->draw_end >= S_HEIGHT)
		maths->draw_end = S_HEIGHT - 1;
	if (maths->side == 0)
		maths->wall_x = ray->p_pos_y + maths->perp_wall_dist * maths->ray_dir_y;
	else
		maths->wall_x = ray->p_pos_x + maths->perp_wall_dist * maths->ray_dir_x;
	maths->wall_x -= floor(maths->wall_x);
}

void	prepare_draw_game(t_game *game, t_maths *maths, t_ray *ray, int x)
{
	int	y;
	int	texture;
	int	px;

	calculating_line_height(maths, ray);
	maths->tex_x = (int)(maths->wall_x * (double)TEX_W);
	maths->step = 1.0 * TEX_H / maths->line_height;
	maths->tex_pos = (maths->draw_start - S_HEIGHT / 2 \
	+ maths->line_height / 2) * maths->step;
	y = maths->draw_start;
	while (y < maths->draw_end)
	{
		maths->tex_y = (int)maths->tex_pos & (TEX_H - 1);
		maths->tex_pos += maths->step;
		maths->tex_num = get_texture(&game->maths);
		px = TEX_H * maths->tex_y + maths->tex_x;
		texture = game->texture[maths->tex_num][px];
		game->buf[y][x] = texture;
		y++;
	}
}

int	raycast(t_game *game)
{
	init_ray(game);
	hook_player(game);
	paint_top_bottom(game);
	maths_need(game, game->map.map_game);
	image_put(game);
	draw_map_2d(game, &game->map);
	return (0);
}

int	main_raycast(t_game *game)
{
	game->win = mlx_new_window(game->mlx, S_WIDTH, S_HEIGHT, "Cub3D");
	game->img.img = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, \
	&game->img.size_l, &game->img.endian);
	if (path_img(game, &game->map) == -1)
		return (ft_error("Error. Path is not valid\n"));
	if (init_texture(game) == -1)
		return (-1);
	load_texture(game);
	dir_player(game);
	start_plane(game);
	mlx_hook(game->win, 2, 1L << 0, press_key, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 6, 1L << 6, mouse_move, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop_hook(game->mlx, &raycast, game);
	mlx_loop(game->mlx);
	return (0);
}
