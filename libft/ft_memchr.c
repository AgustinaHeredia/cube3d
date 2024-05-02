/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 09:32:33 by agheredi          #+#    #+#             */
/*   Updated: 2023/05/08 13:16:26 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	unsigned char	d;
	size_t			i;

	s2 = (unsigned char *)s;
	d = (unsigned char) c;
	i = 0;
	while (i < n && s2[i] != d)
		i++;
	if (i < n && s2[i] == d)
		return (&s2[i]);
	return (NULL);
}
