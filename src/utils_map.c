/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:55:10 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/15 12:55:31 by agheredi         ###   ########.fr       */
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

int	malloc_control(t_game *game)
{
	game->map = malloc(sizeof(t_map) * 1);
	if (!game->map)
		return (ft_error("Error: malloc failed map"));
	game->player = (t_player *)malloc(sizeof(t_player) * 1);
	if (!game->player)
	{
		free(game->map);
		return (ft_error("Error: malloc failed player"));
	}
	return (0);
}
