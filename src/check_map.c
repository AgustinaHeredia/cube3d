/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:39:43 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/30 11:21:54 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	all_char_valid(char **map_game)
{
	int	row;
	int	col;

	row = 0;
	while (map_game[row])
	{
		col = 0;
		while (map_game[row][col] && map_game[row][col] != '\n')
		{
			if (map_game[row][col] != ' '
				&& map_game[row][col] != '\t'
				&& map_game[row][col] != 'N'
				&& map_game[row][col] != 'S'
				&& map_game[row][col] != 'W'
				&& map_game[row][col] != 'E'
				&& map_game[row][col] != '0'
				&& map_game[row][col] != '1')
			{
				return (-1);
			}
			col++;
		}
		row++;
	}
	return (0);
}

void	map_mesures(t_map *map)
{
	int	line;
	int	height;

	line = 0;
	height = 0;
	while (map->map_game[line])
	{
		if ((int)ft_strlen(map->map_game[line]) > map->width)
			map->width = (int)ft_strlen(map->map_game[line]);
		line++;
		height++;
	}
	map->height = height;
}

int	one_player(t_map *map)
{
	int	row;
	int	col;
	int	count;

	row = 0;
	count = 0;
	while (map->map_game[row])
	{
		col = 0;
		while (map->map_game[row][col] && map->map_game[row][col] != '\n')
		{
			if (map->map_game[row][col] == 'N'
				|| map->map_game[row][col] == 'S'
				|| map->map_game[row][col] == 'W'
				|| map->map_game[row][col] == 'E')
			{
				count++;
			}
			col++;
		}
		row++;
	}
	if (count != 1)
		return (-1);
	return (0);
}

static int	check_wall(t_map *map)
{
	int	row;
	int	col;
	int	count;

	row = 0;
	count = 0;
	while (map->map_game[row])
	{
		col = 0;
		while (map->map_game[row][col] && map->map_game[row][col] != '\n')
		{
			if (map->map_game[row][col] == '1')
			{
				count++;
			}
			col++;
		}
		row++;
	}
	if (count < 4)
		return (-1);
	return (0);
}

void	check_map(t_game *game)
{
	if (all_char_valid(game->map.map_game) != 0)
		error_free_exit(game, "Error. Map has invalid char\n");
	if (one_player(&game->map) != 0)
		error_free_exit(game, "Error. Number of player invalid\n");
	if (check_wall(&game->map) != 0)
		error_free_exit(game, "Error. The map has no solution.\n");
	if (check_map_resolt(&game->map, &game->player) != 0)
		error_free_exit(game, "Error. The map has no solution.\n");
	if (check_path(game) != 0)
		error_free_exit(game, "Error. The path is not correct\n");
	if (check_color(game) != 0)
		error_free_exit(game, "Error. The color is not correct\n");
}
