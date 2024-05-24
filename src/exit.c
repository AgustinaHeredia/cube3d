/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:34:10 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/24 12:37:54 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_map(game->map.map_game);
	free_map(game->map.file);
	free(game->maths.side_texture);
	free_texture(game->texture);
	exit(0);
	ft_printf("Ooohhh... you're out of the game\n");
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
	(void)game;
	ft_error(str);
	exit (EXIT_FAILURE);
}

void	free_texture(int **texture)
{
	int	i;

	if (texture != NULL)
	{
		i = 0;
		while (i < 9)
		{
			free(texture[i]);
			i++;
		}
		free(texture);
		texture = NULL;
	}
}
