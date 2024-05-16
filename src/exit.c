/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:34:10 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/15 15:15:17 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map.map_game);
	free_map(game->map.file);
	ft_printf("Ooohhh... you're out of the game\n");
	exit(0);
}

int	free_map(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (-1);
}

void	error_free_exit(t_game *game, char *str)
{
	// free_map(game->map);
	free(game);
	perror(str);
	exit (EXIT_FAILURE);
}
