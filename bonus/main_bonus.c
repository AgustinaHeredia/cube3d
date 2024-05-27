/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/24 13:21:00 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
	main_raycast(&game);
	return (0);
}
