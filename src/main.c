/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/29 12:12:55 by agheredi         ###   ########.fr       */
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
