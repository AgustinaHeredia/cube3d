/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:17:07 by agheredi          #+#    #+#             */
/*   Updated: 2023/10/04 11:02:53 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nwstr;
	size_t	j;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	nwstr = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!nwstr)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		nwstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		nwstr[i + j] = s2[j];
		j++;
	}
	nwstr[i + j] = '\0';
	return (nwstr);
}
