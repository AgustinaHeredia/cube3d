/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/28 14:57:17 by pquintan         ###   ########.fr       */
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
	game.exit = 0;
	init_game(&game);
	read_file(fd, &game);
	check_map(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_error("Error. The release could not be started MLX\n");
		game.exit = 1;
		exit_game(&game);
	}
	if (path_img(&game, &game.map) == -1)
	{
		ft_error("Error. Path is not valid\n");
		game.exit = 1;
		exit_game(&game);
	}
	main_raycast(&game);
	return (0);
}
