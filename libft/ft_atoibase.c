/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoibase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:45:42 by agheredi          #+#    #+#             */
/*   Updated: 2024/05/13 14:53:13 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	fttolower(char c)
{
	if (c >= 'A' && c <= 'F')
		c = c + 32;
	return (c);
}

static int	get_digit(char c, int base)
{
	int	max_digit;

	if (base <= 10)
		max_digit = base + '0';
	else
		max_digit = base - 10 + 'a';
	if (c >= '0' && c <= '9' && max_digit >= c)
		return (c - '0');
	else if (c >= 'a' && c <= 'f' && max_digit >= c)
		return (c + 10 - 'a');
	else
		return (-1);
}

int	ft_atoi_base(const char *str, int base)
{
	int	i;
	int	result;
	int	sign;
	int	digit;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	digit = get_digit(fttolower(str[i]), base);
	while (digit >= 0)
	{
		result = (result * base) + (digit * sign);
		i++;
	}
	return (result);
}
