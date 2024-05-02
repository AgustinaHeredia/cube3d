/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:48:46 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/15 12:12:45 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_numlen_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	pf_putunsigned(unsigned int u)
{
	int		i;
	char	a;

	i = 1;
	if (u >= 10)
	{
		if (pf_putunsigned(u / 10) == -1)
			return (-1);
		a = (u % 10) + '0';
		if (write(1, &a, 1) == -1)
			return (-1);
	}
	else
	{
		a = u + '0';
		if (write(1, &a, 1) == -1)
			return (-1);
	}
	return (i);
}

int	pf_arg_u(t_sc *sc)
{
	unsigned int	u;

	u = va_arg(sc->arg, unsigned int);
	if (pf_putunsigned(u) == -1)
	{
		sc->error = -1;
		return (-1);
	}
	sc -> len += pf_numlen_unsigned(u);
	return (1);
}
