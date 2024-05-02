/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 12:21:53 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/15 12:16:32 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_puthex_lower(unsigned int n)
{
	char	hex[16];
	int		i;
	int		f;

	if (n == 0)
	{
		f = pf_putchar('0');
		return (f);
	}
	i = 0;
	while (n > 0)
	{
		hex[i] = "0123456789abcdef"[n % 16];
		n /= 16;
		i++;
	}
	f = i;
	while (i > 0)
	{
		i--;
		if (pf_putchar(hex[i]) == -1)
			return (-1);
	}
	return (f);
}

int	pf_puthex_upper(unsigned int n)
{
	char	hex[16];
	int		i;
	int		f;

	if (n == 0)
	{
		f = pf_putchar('0');
		return (f);
	}
	i = 0;
	while (n > 0)
	{
		hex[i] = "0123456789ABCDEF"[n % 16];
		n /= 16;
		i++;
	}
	f = i;
	while (i > 0)
	{
		i--;
		if (pf_putchar(hex[i]) == -1)
			return (-1);
	}
	return (f);
}

int	pf_numlen_hex(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	pf_arg_x(t_sc *sc, char c)
{
	unsigned int	num;

	num = va_arg(sc->arg, unsigned int);
	if (c == 'x')
	{
		if (pf_puthex_lower(num) == -1)
		{
			sc->error = -1;
			return (-1);
		}
	}
	else if (c == 'X')
	{
		if (pf_puthex_upper(num) == -1)
		{
			sc->error = -1;
			return (-1);
		}
	}
	sc->len += pf_numlen_hex(num);
	return (1);
}
