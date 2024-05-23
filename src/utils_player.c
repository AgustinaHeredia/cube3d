/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:03:28 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/23 12:16:09 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mesure_player(t_player *player, char view)
{
	player->init_pos = view;
	if (player->init_pos == 'N')
	{
		player->angle = 270;
		// player->dir_x = -1;
	}
	else if (player->init_pos == 'S')
	{
		player->angle = 180;
		// player->dir_x = 1;
	}
	else if (player->init_pos == 'W')
	{
		player->angle = 90;
		// player->dir_y = -1;
	}
	else if (player->init_pos == 'E')
	{
		player->angle = 0;
		// player->dir_y = 1;
	}
} // init_pos == init_pos
// posibilidad que haya que cambiar angulos
