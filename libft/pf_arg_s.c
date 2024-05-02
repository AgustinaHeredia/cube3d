/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:04:52 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/15 12:09:55 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_arg_s(t_sc *sc)
{
	char	*s;

	s = va_arg(sc->arg, char *);
	if (!s)
	{
		if (write(1, "(null)", 6) != 6)
			return (-1);
		sc -> len += 6;
	}
	else
	{
		if (pf_putstr(s) == -1)
		{
			sc->error = -1;
			return (-1);
		}
		sc -> len += pf_strlen(s);
	}
	return (1);
}
