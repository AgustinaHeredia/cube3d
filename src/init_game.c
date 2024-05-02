/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:55:53 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/02 17:14:36 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	malloc_control(t_game *game)
{
	game->map = malloc(sizeof(t_map) * 1);
	if (!game->map)
		return (ft_error("Error: malloc failed map"));
	game->player = (t_player *)malloc(sizeof(t_player) * 1);
	if (!game->player)
	{
		free(game->map);
		return (ft_error("Error: malloc failed player"));
	}
	return (0);
}

void	init_map(t_game *game)
{
	game->map->map_game = NULL;
	game->map->player_x = 0;
	game->map->player_y = 0;
	game->map->height = 3;
	game->map->width = 3;
}

void	init_game(t_game *game)
{
	int	flag;

	flag = malloc_control(game);
	if (flag == 1)
		return ;
	init_map(game);
	game->mlx = NULL;
	game->win = NULL;
}

void	create_map(t_map *map)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup("");
	while (map->file[i])
	{
		if (ft_strncmp(map->file[i], "NO", 2)
			&& ft_strncmp(map->file[i], "SO", 2)
			&& ft_strncmp(map->file[i], "WE", 2)
			&& ft_strncmp(map->file[i], "EA", 2)
			&& ft_strncmp(map->file[i], "F", 1)
			&& ft_strncmp(map->file[i], "C", 1))
		{
			temp = ft_strjoin(temp, "\n");
			temp = ft_strjoin(temp, map->file[i]);
		}
		i++;
	}
	map->map_game = ft_split(temp, '\n');
	free(temp);
}

void	read_file(int fd, t_game *game)
{
	char	*line;
	char	*temp;
	char	*strbigline;

	line = get_next_line(fd);
	strbigline = ft_strdup("");
	while (line != NULL)
	{
		temp = strbigline;
		strbigline = ft_strjoin(strbigline, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->map->file = ft_split(strbigline, '\n');
	free(strbigline);
	create_map(game->map);
}
