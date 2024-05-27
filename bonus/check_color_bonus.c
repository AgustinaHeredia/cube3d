/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:58:14 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/27 14:15:25 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static int	ft_strnumspace(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_isspace(str[i]))
			return (-1);
		i++;
	}
	return (0);
}

static int	color_number(char **floor, char **ceiling)
{
	if (ft_strnumspace(floor[0]) == 0 && ft_strnumspace(floor[1]) == 0
		&& ft_strnumspace(floor[2]) == 0 && ft_strnumspace(ceiling[0]) == 0
		&& ft_strnumspace(ceiling[1]) == 0 && ft_strnumspace(ceiling[2]) == 0)
		return (0);
	return (-1);
}

static int	color_to_hex(int red, int green, int blue)
{
	int	hex_color;

	hex_color = (red << 16) | (green << 8) | blue;
	return (hex_color);
}

static void	mesure_color(t_map *map, char **floor, char **ceiling)
{
	map->floor = color_to_hex(ft_atoi(floor[0]),
			ft_atoi(floor[1]), ft_atoi(floor[2]));
	map->ceiling = color_to_hex(ft_atoi(ceiling[0]),
			ft_atoi(ceiling[1]), ft_atoi(ceiling[2]));
}

int	check_color(t_game *game)
{
	char	**floor;
	char	**ceiling;
	size_t	count_f;
	size_t	count_c;

	count_f = ft_wordcount(game->map.f_color, ',');
	count_c = ft_wordcount(game->map.c_color, ',');
	if (count_f != 3 && count_c != 3)
		return (-1);
	floor = ft_split(game->map.f_color, ',');
	ceiling = ft_split(game->map.c_color, ',');
	if (color_number(floor, ceiling) != 0)
		return (-1);
	if (ft_atoi(floor[0]) < 0 || ft_atoi(floor[0]) > 255
		|| ft_atoi(floor[1]) < 0 || ft_atoi(floor[1]) > 255
		|| ft_atoi(floor[2]) < 0 || ft_atoi(floor[2]) > 255
		|| ft_atoi(ceiling[0]) < 0 || ft_atoi(ceiling[0]) > 255
		|| ft_atoi(ceiling[1]) < 0 || ft_atoi(ceiling[1]) > 255
		|| ft_atoi(ceiling[2]) < 0 || ft_atoi(ceiling[2]) > 255)
		return (-1);
	mesure_color(&game->map, floor, ceiling);
	free_map(floor);
	free_map(ceiling);
	return (0);
}
