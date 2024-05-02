/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:06:59 by agheredi          #+#    #+#             */
/*   Updated: 2023/05/19 12:54:50 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*chr;

	i = 0;
	chr = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			chr = (char *)&s[i];
			return (chr);
		}
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)&s[i]);
	return (chr);
}
