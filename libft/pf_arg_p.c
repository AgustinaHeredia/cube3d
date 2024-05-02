/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:51:11 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/15 12:07:15 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putptr(t_sc *sc, unsigned long p)
{
	char			hex[16];
	int				i;

	i = 0;
	while (p > 0 && i < 16)
	{
		hex[i] = "0123456789abcdef"[p % 16];
		p /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		if (pf_putchar(hex[i]) == -1)
		{
			sc->error = -1;
			return (-1);
		}
	}
	return (1);
}

int	pf_numlen_ptr(unsigned long p)
{
	int				len;

	len = 0;
	if (p == 0)
		return (1);
	while (p > 0)
	{
		p /= 16;
		len++;
	}
	return (len);
}

int	pf_arg_p(t_sc *sc)
{
	unsigned long	p;

	p = va_arg(sc->arg, unsigned long);
	if (!p)
	{
		if (write(1, "0x0", 3) == -1)
		{
			sc->error = -1;
			return (-1);
		}
		sc->len += 3;
	}
	else
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		if (pf_putptr(sc, p) == -1)
		{
			sc->error = -1;
			return (-1);
		}
		sc->len += pf_numlen_ptr(p) + 2;
	}
	return (1);
}
