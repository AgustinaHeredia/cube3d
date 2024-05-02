/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:32:23 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/02 14:44:51 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit_game(game);
	// if (key_code == KEY_W)
	// 	move_w(game);
	// if (key_code == KEY_A)
	// 	move_a(game);
	// if (key_code == KEY_S)
	// 	move_s(game);
	// if (key_code == KEY_D)
	// 	move_d(game);
	return (0);
}