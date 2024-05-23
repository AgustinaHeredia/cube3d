/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:55:10 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/23 13:15:07 by agheredi         ###   ########.fr       */
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
	char	*temp1;

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
			temp1 = ft_strjoin(temp, "\n");
			free(temp);
			temp = ft_strjoin(temp1, map->file[i]);
			free(temp1);
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
void	angle_player(t_game *game)
{
	if (game->player.init_pos == 'N')
		game->player.angle = 270;
	else if (game->player.init_pos == 'S')
		game->player.angle = 180;
	else if (game->player.init_pos == 'W')
		game->player.angle = 90;
	else if (game->player.init_pos == 'E')
		game->player.angle = 0;
}

void	dir_player(t_game *game)
{
	if (game->player.init_pos == 'N') // este caso esta bien
	{
		game->ray.dir_vector_x = -1;
		game->ray.dir_vector_y = 0;
	}
	else if (game->player.init_pos == 'S') // este caso esta bien
	{
		game->ray.dir_vector_x = 1;
		game->ray.dir_vector_y = 0;
	}
	else if (game->player.init_pos == 'W')
	{
		game->ray.dir_vector_x = 0;
		game->ray.dir_vector_y = 1;
	}
	else if (game->player.init_pos == 'E')
	{
		game->ray.dir_vector_x = 0;
		game->ray.dir_vector_y = -1;
	}
} // el eje X apunta hacia la derecha y el eje Y apunta hacia arriba.
