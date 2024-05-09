/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:55:10 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/09 12:44:58 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_spalloc(size_t count)
{
	void	*ptr;
	size_t	i;

	ptr = (char *) malloc(sizeof(char) * count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < count)
	{
		((unsigned char *)ptr)[i] = ' ';
		i++;
	}
	return (ptr);
}

void	create_map(t_map *map)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup("");
	while (map->file[i])
	{
		if (ft_strncmp(map->file[i], "NO", 2)
			&& ft_strncmp(map->file[i], "SO", 2)
			&& ft_strncmp(map->file[i], "WE", 2)
			&& ft_strncmp(map->file[i], "EA", 2)
			&& ft_strncmp(map->file[i], "F", 1)
			&& ft_strncmp(map->file[i], "C", 1))
		{
			temp = ft_strjoin(temp, "\n");
			temp = ft_strjoin(temp, map->file[i]);
		}
		i++;
	}
	map->map_game = ft_split(temp, '\n');
	free(temp);
}
