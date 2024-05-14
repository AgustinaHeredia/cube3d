/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:55:13 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/14 17:50:56 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	path_mesure(t_game *game)
{
	int		i;
	char	*temp;

	i = 0;
	while (game->map->file[i] && (ft_wordcount(game->map->file[i], ' ') == 2))
	{
		temp = game->map->file[i];
		if (!ft_strncmp(game->map->file[i], "NO ", 3))
			game->map->path_no = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map->file[i], "SO ", 3))
			game->map->path_so = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map->file[i], "WE ", 3))
			game->map->path_we = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map->file[i], "EA ", 3))
			game->map->path_ea = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map->file[i], "F ", 2))
			game->map->f_color = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map->file[i], "C ", 2))
			game->map->c_color = ft_strdup(ft_strrchr(temp, ' ') + 1);
		i++;
	}
}

static int	path_img(t_game *game, t_map *map)
{
	int	w;
	int	h;

	game->path_n = mlx_xpm_file_to_image(game->mlx, map->path_no, &w, &h);
	printf("HOLIS\n");
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

int	check_path(t_game *game)
{
	path_mesure(game);
	if (!game->map->path_no || !game->map->path_so
		|| !game->map->path_we || !game->map->path_ea
		|| !game->map->f_color || !game->map->c_color)
		return (-1);
	if (path_img(game, game->map) != 0)
		return (-1);
	return (0);
}
