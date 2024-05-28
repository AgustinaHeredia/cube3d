/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:55:53 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/28 14:55:33 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	initialize_player(t_game *game)
{
	game->player.player_x = 0;
	game->player.player_y = 0;
	game->player.up_down = 0;
	game->player.left_right = 0;
	game->player.rote = 0;
	game->player.angle = 0;
}

void	init_map(t_game *game)
{
	game->map.map_game = NULL;
	game->map.height = 0;
	game->map.width = 0;
	game->player.init_x = 0;
	game->player.init_y = 0;
	game->map.path_no = NULL;
	game->map.path_so = NULL;
	game->map.path_we = NULL;
	game->map.path_ea = NULL;
	game->map.f_color = NULL;
	game->map.c_color = NULL;
}

static void	space_map(t_map *map)
{
	int		i;
	char	*temp;
	char	*temp2;
	int		len;

	map_mesures(map);
	i = 0;
	while (map->map_game[i])
	{
		len = ft_strlen(map->map_game[i]);
		if (len < map->width)
		{
			temp = ft_spalloc(map->width - len);
			temp2 = ft_strdup(map->map_game[i]);
			free(map->map_game[i]);
			map->map_game[i] = ft_strjoin(temp2, temp);
			free(temp);
			free(temp2);
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
		temp = ft_strdup(strbigline);
		free(strbigline);
		strbigline = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	game->map.file = ft_split(strbigline, '\n');
	free(strbigline);
	check_map_position(&game->map);
	create_map(&game->map);
	space_map(&game->map);
}

void	init_game(t_game *game)
{
	game->maths.side_texture = malloc(sizeof(int) * 3);
	if (!game->maths.side_texture)
		return ;
	init_map(game);
	initialize_player(game);
	game->mlx = NULL;
	game->win = NULL;
	game->path_n = NULL;
	game->path_s = NULL;
	game->path_w = NULL;
	game->path_e = NULL;
}
