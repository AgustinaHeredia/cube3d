/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:00:10 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/08 10:47:44 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fail(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_readfile(int fd, char *stash)
{
	char		*tmp;
	int			fd_read;

	fd_read = 1;
	tmp = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ft_fail(&stash));
	while ((!ft_strchr_gnl(stash, '\n') && fd_read != 0))
	{
		fd_read = read(fd, tmp, BUFFER_SIZE);
		if (fd_read == -1)
		{
			free(stash);
			return (ft_fail(&tmp));
		}
		tmp[fd_read] = '\0';
		stash = ft_strjoin_gnl(stash, tmp);
		if (!stash)
			return (ft_fail(&tmp));
	}
	free(tmp);
	return (stash);
}

char	*ft_get_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *) malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_move_line(char *stash)
{
	char	*nwstash;
	int		i;
	int		j;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (ft_fail(&stash));
	i += (stash[i] == '\n');
	nwstash = (char *) malloc((ft_strlen_gnl(stash) - i + 1));
	if (!nwstash)
		return (ft_fail(&stash));
	j = 0;
	while (stash[i + j])
	{
		nwstash[j] = stash[i + j];
		j++;
	}
	nwstash[j] = '\0';
	free(stash);
	return (nwstash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = ft_readfile(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	if (line == NULL)
		return (ft_fail(&stash[fd]));
	stash[fd] = ft_move_line(stash[fd]);
	return (line);
}
