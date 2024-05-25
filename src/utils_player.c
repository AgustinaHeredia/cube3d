/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:03:28 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/25 20:00:03 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mesure_player(t_player *player, char view)
{
	player->init_pos = view;
	if (player->init_pos == 'N')
	{
		player->angle = 270;
	}
	else if (player->init_pos == 'S')
	{
		player->angle = 180;
	}
	else if (player->init_pos == 'W')
	{
		player->angle = 90;
	}
	else if (player->init_pos == 'E')
	{
		player->angle = 0;
	}
}

size_t	ft_wordcount(char *s, char sep)
{
	size_t	count;
	size_t	i;
	int		separator_found;

	i = 0;
	count = 0;
	separator_found = 1;
	while (s[i] != '\0')
	{
		if (s[i] == sep)
			separator_found = 1;
		else if (separator_found == 1)
		{
			count++;
			separator_found = 0;
		}
		i++;
	}
	return (count);
}

void	check_map_position(t_map *map)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (map->file[i])
	{
		if (ft_strncmp(map->file[i], "NO", 2)
			&& ft_strncmp(map->file[i], "SO", 2)
			&& ft_strncmp(map->file[i], "WE", 2)
			&& ft_strncmp(map->file[i], "EA", 2)
			&& ft_strncmp(map->file[i], "F", 1)
			&& ft_strncmp(map->file[i], "C", 1))
		{
			if (flag != 6)
			{
				ft_error("Error. The file content is not correct\n");
				exit(1);
			}
		}
		else
			flag++;
		i++;
	}
}

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t')
	{
		return (2048);
	}
	return (0);
}
