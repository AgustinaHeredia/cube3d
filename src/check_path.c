/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:55:13 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/25 19:44:54 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	path_count(t_game *game)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (game->map.file[i])
	{
		if (!ft_strncmp(game->map.file[i], "NO ", 3))
			count++;
		if (!ft_strncmp(game->map.file[i], "SO ", 3))
			count++;
		if (!ft_strncmp(game->map.file[i], "WE ", 3))
			count++;
		if (!ft_strncmp(game->map.file[i], "EA ", 3))
			count++;
		if (!ft_strncmp(game->map.file[i], "F ", 2))
			count++;
		if (!ft_strncmp(game->map.file[i], "C ", 2))
			count++;
		i++;
	}
	if (count != 6)
		return (-1);
	return (0);
}

static void	path_mesure(t_game *game)
{
	int		i;
	char	*temp;

	i = 0;
	while (game->map.file[i])
	{
		temp = game->map.file[i];
		if (!ft_strncmp(game->map.file[i], "NO ", 3) && !game->map.path_no)
			game->map.path_no = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "SO ", 3) && !game->map.path_so)
			game->map.path_so = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "WE ", 3) && !game->map.path_we)
			game->map.path_we = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "EA ", 3) && !game->map.path_ea)
			game->map.path_ea = ft_strdup(ft_strrchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "F ", 2) && !game->map.f_color)
			game->map.f_color = ft_strdup(ft_strchr(temp, ' ') + 1);
		if (!ft_strncmp(game->map.file[i], "C ", 2) && !game->map.c_color)
			game->map.c_color = ft_strdup(ft_strchr(temp, ' ') + 1);
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
	if (path_count(game) != 0)
		return (-1);
	path_mesure(game);
	if (!game->map.path_no || !game->map.path_so
		|| !game->map.path_we || !game->map.path_ea
		|| !game->map.f_color || !game->map.c_color)
		return (-1);
	if (path_ok(&game->map) != 0)
		return (-1);
	return (0);
}
