/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:58:14 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/09 15:27:52 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_color(t_game *game)
{
	char	**floor;
	char	**ceiling;
	size_t	count_f;
	size_t	count_c;

	count_f = ft_wordcount(game->map->f_color, ',');
	count_c = ft_wordcount(game->map->c_color, ',');
	if (count_f != 3 && count_c != 3)
		return (-1);	
	floor = ft_split(game->map->f_color, ',');
	ceiling = ft_split(game->map->c_color, ',');
	if (ft_atoi(floor[0]) < 0 || ft_atoi(floor[0]) > 255
		|| ft_atoi(floor[1]) < 0 || ft_atoi(floor[1]) > 255
		|| ft_atoi(floor[2]) < 0 || ft_atoi(floor[2]) > 255
		|| ft_atoi(ceiling[0]) < 0 || ft_atoi(ceiling[0]) > 255
		|| ft_atoi(ceiling[1]) < 0 || ft_atoi(ceiling[1]) > 255
		|| ft_atoi(ceiling[2]) < 0 || ft_atoi(ceiling[2]) > 255)
		return (-1);
	return (0);
}
