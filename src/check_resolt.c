/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resolt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:07:13 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/06 15:44:47 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	flood_fill(t_map *map, char **temp, int x, int y)
{
	if (x < 0 || x >= map->height || y < 0 || y >= map->width
		|| temp[x][y] == '1' || temp[x][y] == 'F' || temp[x][y] == ' ')
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
		ft_error("Error. No se ha podido asignar memoria al map Temp\n");
	i = 0;
	while (i < height)
	{
		temp[i] = ft_strdup(map[i]);
		if (!temp[i])
		{
			free_map(temp);
			ft_error("Error. No se ha podido asignar memoria en mapTemp\n");
		}
		i++;
	}
	temp[height] = NULL;
	return (temp);
}

static void	player_position(t_map *map)
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
				map->player_x = row;
				map->player_y = col;
			}
			col++;
		}
		row++;
	}
}

static int	check_flood(char **temp, int i, int j)
{
	int	len;
	int	row;

	row = 0;
	while (temp[row])
		row++;
	len = ft_strlen(temp[i]);
	printf("ROW = %d, i = %d, j = %d\n", row, i, j);
	if (temp[0][j] == 'F' || temp[row - 1][j] == 'F')
		return (-1);
	if (temp[i][0] == 'F'
		|| temp[i][len - 1] == 'F')
		return (-1);
	else
		return (0);
}

int	check_map_resolt(t_map *map)
{
	char	**temp;
	int		i;
	int		j;

	player_position(map);
	temp = create_copy_map(map->map_game, map->height);
	flood_fill(map, temp, map->player_x, map->player_y);
	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (check_flood(temp, i, j) == -1)
			{
				free(temp);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free_map(temp);
	return (0);
}
