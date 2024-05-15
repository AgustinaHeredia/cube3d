/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/15 23:14:53 by agusheredia      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		fd;

	fd = check_arg_and_fd(argc, argv);
	if (fd == 1)
		return (1);
	// game = (t_game *)malloc(sizeof(t_game) * 1);
	// if (!game)
	// 	return (ft_error("Error. Failed to malloc.\n"));
	init_game(&game);
	read_file(fd, &game);
	check_map(&game);
	//printf("El char de init player es %c\n", game->player->player_view);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_error("Error. The release could not be started MLX\n"));
	init_raycast(&game); // raycast
	// init_window(&game);
	// cleaning_all(game);
	return (0);
}
