/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/16 15:36:58 by pquintan         ###   ########.fr       */
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
	init_raycast(&game); // raycast
	// init_window(game);
	// cleaning_all(game);
	return (0);
}
