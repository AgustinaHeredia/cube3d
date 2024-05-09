/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:55:53 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/09 12:45:00 by agheredi         ###   ########.fr       */
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
	game->map->height = 0;
	game->map->width = 0;
	game->player->player_x = 0;
	game->player->player_y = 0;
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

static void	space_map(t_map *map)
{
	int		i;
	char	*temp;
	int		len;

	map_mesures(map);
	i = 0;
	while (map->map_game[i])
	{
		len = ft_strlen(map->map_game[i]);
		if (len < map->width)
		{
			temp = ft_spalloc(map->width - len);
			map->map_game[i] = ft_strjoin(map->map_game[i], temp);
			free(temp);
		}
		i++;
	}
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
	space_map(game->map);
}
