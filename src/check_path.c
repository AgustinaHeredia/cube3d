/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:55:13 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/16 15:34:01 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	path_mesure(t_game *game)
{
	int		i;
	char	*temp;

	i = 0;
	while (game->map.file[i] && (ft_wordcount(game->map.file[i], ' ') == 2))
	{
		temp = game->map.file[i];
		if (!ft_strncmp(game->map.file[i], "NO ", 3))
			game->map.path_no = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "SO ", 3))
			game->map.path_so = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "WE ", 3))
			game->map.path_we = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "EA ", 3))
			game->map.path_ea = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "F ", 2))
			game->map.f_color = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "C ", 2))
			game->map.c_color = ft_strdup(ft_strrchr(temp, ' ') + 1);
		i++;
	}
}

static int	path_ok(t_map *map)
{
	if (ft_strncmp(map->path_no + ft_strlen(map->path_no) - 4, ".xpm", 4))
		return (-1);
	if (ft_strncmp(map->path_so + ft_strlen(map->path_so) - 4, ".xpm", 4))
		return (-1);
	if (ft_strncmp(map->path_we + ft_strlen(map->path_we) - 4, ".xpm", 4))
		return (-1);
	if (ft_strncmp(map->path_ea + ft_strlen(map->path_ea) - 4, ".xpm", 4))
		return (-1);
	return (0);
}

int	check_path(t_game *game)
{
	path_mesure(game);
	if (!game->map.path_no || !game->map.path_so
		|| !game->map.path_we || !game->map.path_ea
		|| !game->map.f_color || !game->map.c_color)
		return (-1);
	if (path_ok(&game->map) != 0)
		return (-1);
	return (0);
}
