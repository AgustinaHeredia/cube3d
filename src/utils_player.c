/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:03:28 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/16 16:08:48 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mesure_player(t_player *player, char view)
{
	player->init_pos = view;
	if (player->init_pos == 'N')
		player->angle = 270;
	else if (player->init_pos == 'S')
		player->angle = 180;
	else if (player->init_pos == 'W')
		player->angle = 90;
	else if (player->init_pos == 'E')
		player->angle = 0;
} // init_pos == init_pos
// posibilidad que haya que cambiar angulos
