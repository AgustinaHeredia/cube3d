/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:03:28 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/24 09:52:42 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	mesure_player(t_player *player, char view)
{
	player->init_pos = view;
	if (player->init_pos == 'N')
	{
		player->angle = 270;
	}
	else if (player->init_pos == 'S')
	{
		player->angle = 180;
	}
	else if (player->init_pos == 'W')
	{
		player->angle = 90;
	}
	else if (player->init_pos == 'E')
	{
		player->angle = 0;
	}
}

size_t	ft_wordcount(char *s, char sep)
{
	size_t	count;
	size_t	i;
	int		separator_found;

	i = 0;
	count = 0;
	separator_found = 1;
	while (s[i] != '\0')
	{
		if (s[i] == sep)
			separator_found = 1;
		else if (separator_found == 1)
		{
			count++;
			separator_found = 0;
		}
		i++;
	}
	return (count);
}
