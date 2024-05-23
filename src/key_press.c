/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:32:23 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/23 14:17:06 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	else if (key_code == KEY_W)
		game->player.up_down = 1;
	else if (key_code == KEY_A)
		game->player.left_right = -1;
	else if (key_code == KEY_S)
		game->player.up_down = -1;
	else if (key_code == KEY_D)
		game->player.left_right = 1;
	else if (key_code == KEY_LEFT)
		game->player.rote = 1;
	else if (key_code == KEY_RIGHT)
		game->player.rote = -1;
	return (0);
}

int	key_release(int key_code, t_game *game)
{
	if (key_code == KEY_W)
		game->player.up_down = 0;
	else if (key_code == KEY_A)
		game->player.left_right = 0;
	else if (key_code == KEY_S)
		game->player.up_down = 0;
	else if (key_code == KEY_D)
		game->player.left_right = 0;
	else if (key_code == KEY_LEFT)
		game->player.rote = 0;
	else if (key_code == KEY_RIGHT)
		game->player.rote = 0;
	return (0);
}
