/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:31:03 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/15 13:42:00 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate_player(t_game *game, int rote)
{}

void	move_player(t_game *game, double move_x, double move_y)
{}

void	key_release(t_keydata keydata, t_game *game)
{
	if (keydata.key == KEY_W && keydata.action == KEY_RELEASE)
		game->player->up_down = 0;
	else if (keydata.key == KEY_A && keydata.action == KEY_RELEASE)
		game->player->left_right = 0;
	else if (keydata.key == KEY_S && keydata.action == KEY_RELEASE)
		game->player->up_down = 0;
	else if (keydata.key == KEY_D && keydata.action == KEY_RELEASE)
		game->player->left_right = 0;
	else if (keydata.key == KEY_LEFT && keydata.action == KEY_RELEASE)
		game->player->rote = 0;
	else if (keydata.key == KEY_RIGHT && keydata.action == KEY_RELEASE)
		game->player->rote = 0;
}

void	hook_player(t_game *game, double move_x, double move_y)
{
	if (game->player->rote == 1)
		rotate_player(game, 1);
	if (game->player->rote == -1)
		rotate_player(game, -1);
	if (game->player->up_down == 1)
	{
		move_x = ;
		move_y = ;
	}
	if (game->player->up_down == -1)
	{
		move_x = ;
		move_y = ;
	}
	if (game->player->left_right == 1)
	{
		move_x = ;
		move_y = ;
	}
	if (game->player->left_right == -1)
	{
		move_x = ;
		move_y = ;
	}
	move_player(game, move_x, move_y);
}
