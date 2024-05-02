/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:18:15 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/02 14:12:08 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	check_map_extention(char *argv)
{
	char	*extention;

	extention = ft_strnstr(argv, ".cub", ft_strlen(argv));
	if (!extention)
		return (0);
	return (1);
}

static int	ft_open_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	check_arg_and_fd(int argc, char **argv)
{
	int		fd;
	int		flag;

	if (argc != 2)
		return (ft_error("Error. Invalid number of arguments\n"));
	flag = check_map_extention(argv[1]);
	if (flag == 0)
		return (ft_error("Error. Invalid file extension.\n"));
	fd = ft_open_file(argv[1]);
	if (fd == -1)
		return (ft_error("Error.The file could not be opened\n"));
	return (fd);
}
