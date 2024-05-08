/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:39:43 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/08 10:32:33 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	all_char_valid(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (map->map_game[row])
	{
		col = 0;
		while (map->map_game[row][col])
		{
			if (map->map_game[row][col] != ' '
				&& map->map_game[row][col] != '\t'
				&& map->map_game[row][col] != 'N'
				&& map->map_game[row][col] != 'S'
				&& map->map_game[row][col] != 'W'
				&& map->map_game[row][col] != 'E'
				&& map->map_game[row][col] != '0'
				&& map->map_game[row][col] != '1')
				return (-1);
			col++;
		}
		row++;
	}
	return (0);
}

static void	map_mesures(t_map *map)
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
	printf("Height es %d y width %d\n", map->height, map->width);
}

void	check_map(t_game *game)
{
	map_mesures(game->map);
	if (all_char_valid(game->map) != 0)
		error_free_exit(game, "Error. Map has invalid char\n");
	if (check_map_resolt(game->map) != 0)
		error_free_exit(game, "Error. El mapa no tiene solución.\n");
	// if (perimeter_check(game) != 0)
	// 	error_free_exit(game, "Error. El perimetro no es correcto\n");
	else
		ft_printf("El mapa es correcto, seguimos\n");
}
