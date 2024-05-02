/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:55:53 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/02 14:59:25 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

void	init_map(t_game *game)
{
	game->map->map_game = NULL;
	game->map->player_x = 0;
	game->map->player_y = 0;
	game->map->height = 3;
	game->map->width = 3;
}

void	init_game(t_game *game)
{
	int	flag;

	flag = malloc_control(game);
	if (flag == 1)
		return ;
	init_map(game);
	game->mlx = NULL;
	game->win = NULL;
}

// void	read_map(int fd, t_game *game)
// {
// 	char	*line;
// 	char	*temp;

// 	line = get_next_line(fd);
// 	game->height = 0;
// 	game->width = ft_strlen(line) - 1;
// 	game->strbigline = ft_strdup("");
// 	while (line != NULL)
// 	{
// 		game->height++;
// 		temp = game->strbigline;
// 		game->strbigline = ft_strjoin(game->strbigline, line);
// 		free(temp);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	close(fd);
// 	game->map = ft_split(game->strbigline, '\n');
// }