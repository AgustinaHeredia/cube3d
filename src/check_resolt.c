/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resolt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:07:13 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/30 13:26:51 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	flood_fill(t_map *map, char **temp, int x, int y)
{
	int	len;

	if (!map->map_game[x])
		return ;
	len = ft_strlen(map->map_game[x]);
	if (x == map->width)
		return ;
	if (x <= 0 || x > map->height || y <= 0 || y > map->width || \
	temp[x][y] == '1' || temp[x][y] == 'F' || temp[x][y] == ' ')
		return ;
	temp[x][y] = 'F';
	flood_fill(map, temp, (x + 1), y);
	flood_fill(map, temp, (x - 1), y);
	flood_fill(map, temp, x, (y + 1));
	flood_fill(map, temp, x, (y - 1));
}

static char	**create_copy_map(char **map, int height)
{
	char	**temp;
	int		i;

	temp = (char **)malloc((height + 1) * sizeof(char *));
	if (!temp)
		ft_error("Error. Couldn't assign memory to the map\n");
	i = 0;
	while (i < height)
	{
		temp[i] = ft_strdup(map[i]);
		if (!temp[i])
		{
			free_map(temp);
			ft_error("Error. Couldn't assign memory to the map\n");
		}
		i++;
	}
	temp[height] = NULL;
	return (temp);
}

static void	player_position(t_map *map, t_player *player)
{
	int	row;
	int	col;

	row = 0;
	while (map->map_game[row])
	{
		col = 0;
		while (map->map_game[row][col])
		{
			if (map->map_game[row][col] == 'N'
				|| map->map_game[row][col] == 'S'
				|| map->map_game[row][col] == 'W'
				|| map->map_game[row][col] == 'E')
			{
				player->init_x = row;
				player->init_y = col;
				player->player_x = row + 0.2;
				player->player_y = col + 0.2;
				mesure_player(player, map->map_game[row][col]);
			}
			col++;
		}
		row++;
	}
}

static int	check_flood(char **map, char *line, int row)
{
	int	len;
	int	x;
	int	start;

	len = ft_strlen(line) - 1;
	x = 0;
	start = 0;
	while (line[start] == ' ')
		start++;
	if (line[start] == 'F' || line[len] == 'F')
		return (-1);
	while (line[x])
	{
		if (line[x] == 'F')
		{
			if (row == 0 || !map[row + 1])
				return (-1);
			if (map[row - 1][x] == ' ' || map[row + 1][x] == ' ')
				return (-1);
			if (map[row][x - 1] == ' ' || map[row][x + 1] == ' ')
				return (-1);
		}
		x++;
	}
	return (0);
}

int	check_map_resolt(t_map *map, t_player *player)
{
	char	**temp;
	int		i;

	player_position(map, player);
	temp = create_copy_map(map->map_game, map->height);
	flood_fill(map, temp, player->init_x, player->init_y);
	i = 0;
	while (temp[i])
	{
		if (check_flood(temp, temp[i], i) == -1)
		{
			free_map(temp);
			return (-1);
		}
		i++;
	}
	free_map(temp);
	return (0);
}
