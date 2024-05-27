/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_door_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:13:17 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/27 14:36:38 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static int	check_wall_door(char **map, int x, int y)
{
	if ((map[x][y - 1] == '1' && map[x][y + 1] == '1') && \
	(map[x - 1][y] == '0' && map[x + 1][y] == '0'))
		return (0);
	if ((map[x][y - 1] == '0' && map[x][y + 1] == '0') && \
	(map[x - 1][y] == '1' && map[x + 1][y] == '1'))
		return (0);
	else
		return (-1);
}

int	check_door(char **map_game)
{
	int	row;
	int	col;

	row = 0;
	while (map_game[row])
	{
		col = 0;
		while (map_game[row][col] && map_game[row][col] != '\n')
		{
			if (map_game[row][col] == 'D' || map_game[row][col] == 'd')
			{
				if (check_wall_door(map_game, row, col) != 0)
					return (-1);
			}
			col++;
		}
		row++;
	}
	return (0);
}
