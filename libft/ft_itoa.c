/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:51:21 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/05 11:09:15 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while ((n / 10) != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*strnbr;
	int				len;
	unsigned int	nb;

	len = ft_nbrlen(n);
	if (n < 0)
		nb = -n;
	else
		nb = n;
	strnbr = (char *) malloc(sizeof(char) * len + 1);
	if (!strnbr)
		return (0);
	strnbr[len] = '\0';
	while (len-- > 0)
	{
		strnbr[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		strnbr[0] = '-';
	return (strnbr);
}
