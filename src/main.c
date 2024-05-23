/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/21 10:57:42 by pquintan         ###   ########.fr       */
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
	init_game(&game);
	read_file(fd, &game);
	check_map(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		return (ft_error("Error. The release could not be started MLX\n"));
	main_raycast(&game); // raycast
	// init_window(game);
	exit_game(&game);
	return (0);
}
