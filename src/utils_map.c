/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:55:10 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/24 09:50:31 by pquintan         ###   ########.fr       */
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

void	start_plane(t_game *game)
{
	if (game->player.init_pos == 'N')
	{
		game->ray.plane_x = 0;
		game->ray.plane_y = 0.66;
	}
	else if (game->player.init_pos == 'S')
	{
		game->ray.plane_x = 0;
		game->ray.plane_y = -0.66;
	}
	else if (game->player.init_pos == 'W')
	{
		game->ray.plane_x = -0.66;
		game->ray.plane_y = 0;
	}
	else if (game->player.init_pos == 'E')
	{
		game->ray.plane_x = 0.66;
		game->ray.plane_y = 0;
	}
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
	if (game->player.init_pos == 'N')
	{
		game->ray.dir_vector_x = -1;
		game->ray.dir_vector_y = 0;
	}
	else if (game->player.init_pos == 'S')
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
}
