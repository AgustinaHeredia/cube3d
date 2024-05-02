/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:36:45 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/15 12:00:53 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_search_arg(const char format, t_sc *sc)
{
	int	res;

	res = 0;
	if (format == 'c')
		res = pf_arg_c(sc);
	else if (format == 's')
		res = pf_arg_s(sc);
	else if (format == 'p')
		res = pf_arg_p(sc);
	else if (format == 'd' || format == 'i')
		res = pf_arg_d(sc);
	else if (format == 'u')
		res = pf_arg_u(sc);
	else if (format == 'x' || format == 'X')
		res = pf_arg_x(sc, format);
	else
		res = pf_read_text(sc, format);
	return (res);
}
