/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/02 17:56:41 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	fd = check_arg_and_fd(argc, argv);
	if (fd == 1)
		return (1);
	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (!game)
		return (ft_error("Error. Failed to malloc.\n"));
	init_game(game);
	read_file(fd, game);
	int i = 0;
	while (i < 10)
		printf("%s\n", game->map->map_game[i++]);
	// check_map(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("Error. The release could not be started MLX\n"));
	init_window(game);
	mlx_destroy_window(game->mlx, game->win);
    free(game->mlx);
	// cleaning_all(game);
	return (0);
}
