/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:50:27 by agusheredia       #+#    #+#             */
/*   Updated: 2024/05/22 15:05:50 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	path_img(t_game *game, t_map *map) // new var void * in game struct
{
	int	w;
	int	h;

	printf("Entra path_ing\n");
	game->path_n = mlx_xpm_file_to_image(game->mlx, map->path_no, &w, &h);
	if (!game->path_n)
		return (-1);
	game->path_s = mlx_xpm_file_to_image(game->mlx, map->path_so, &w, &h);
	if (!game->path_s)
		return (-1);
	game->path_w = mlx_xpm_file_to_image(game->mlx, map->path_we, &w, &h);
	if (!game->path_w)
		return (-1);
	game->path_e = mlx_xpm_file_to_image(game->mlx, map->path_ea, &w, &h);
	if (!game->path_e)
		return (-1);
	return (0);
}
