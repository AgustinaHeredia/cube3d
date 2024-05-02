/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:33:56 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/15 11:58:36 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_sc	*pf_inicializa_sc(t_sc *sc)
{
	sc->len = 0;
	sc ->width = 0;
	sc->error = 0;
	return (sc);
}

static int	pf_eval_format(t_sc *sc, const char *format)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			res = pf_search_arg(format[i + 1], sc);
			if (res == -1)
				return (res);
			i = i + 2;
		}
		else
		{
			res = pf_read_text(sc, format[i]);
			if (res == -1)
				return (res);
			i++;
		}
	}
	return (res);
}

int	ft_printf(char const *format, ...)
{
	t_sc	*sc;
	int		result;
	int		flag;

	sc = (t_sc *) malloc(sizeof(t_sc));
	if (!sc)
		return (-1);
	pf_inicializa_sc(sc);
	va_start(sc->arg, format);
	result = 0;
	flag = pf_eval_format(sc, format);
	sc->error = flag;
	va_end(sc->arg);
	result += sc->len;
	if (sc->error == -1)
	{
		free(sc);
		return (-1);
	}
	free(sc);
	return (result);
}
