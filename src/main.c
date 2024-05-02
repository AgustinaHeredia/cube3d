/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:17:48 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/02 17:44:23 by agheredi         ###   ########.fr       */
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
	check_map(game);
	// game->mlx = mlx_init();
	// if (!game->mlx)
	// 	return (ft_error("Error. The release could not be started MLX\n"));
	// init_window(game);
	// cleaning_all(game);
	return (0);
}
