/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:45:30 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/15 12:04:08 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_arg_d(t_sc *sc)
{
	int	d;

	d = va_arg(sc->arg, int);
	if (pf_putnbr(d) == -1)
	{
		sc->error = -1;
		return (-1);
	}
	sc -> len += pf_nbrlen(d);
	return (1);
}
