/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:39:43 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/06 13:55:09 by agheredi         ###   ########.fr       */
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
	map->height = row;
	map->width = col;
	printf("Height es %d y width %d\n", map->height, map->width);
	return (0);
}

void	check_map(t_game *game)
{
	if (all_char_valid(game->map) != 0)
		error_free_exit(game, "Error. Map has invalid char\n");
	if (check_map_resolt(game->map) != 0)
		error_free_exit(game, "Error. El mapa no tiene solución.\n");
	// if (perimeter_check(game) != 0)
	// 	error_free_exit(game, "Error. El perimetro no es correcto\n");
	else
		ft_printf("El mapa es correcto, seguimos\n");
}
