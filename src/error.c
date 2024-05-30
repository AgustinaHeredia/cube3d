/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:19:18 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/30 16:31:06 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}

int	ft_exit_map(char **map1, char **map2)
{
	free_map(map1);
	free_map(map2);
	return (-1);
}
