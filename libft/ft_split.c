/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:49:12 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/05 11:04:10 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char *s, char sep)
{
	size_t	count;
	size_t	i;
	int		separator_found;

	i = 0;
	count = 0;
	separator_found = 1;
	while (s[i] != '\0')
	{
		if (s[i] == sep)
			separator_found = 1;
		else if (separator_found == 1)
		{
			count++;
			separator_found = 0;
		}
		i++;
	}
	return (count);
}

static size_t	ft_len_word(char *from, char sep)
{
	size_t	len;

	len = 0;
	while (from[len] != '\0' && from[len] != sep)
		len++;
	return (len);
}

static char	**ft_write_split(char **lstword, char const *s, char sep)
{
	size_t			words;
	size_t			lenword;
	unsigned int	i;

	i = 0;
	words = ft_wordcount((char *) s, sep);
	while (i < words)
	{
		while (*s && *s == sep)
			s++;
		lenword = ft_len_word ((char *) s, sep);
		lstword[i] = ft_substr(s, 0, lenword);
		if (!lstword[i])
		{
			while (i > 0)
				free(lstword[--i]);
			free(lstword);
			return (NULL);
		}
		s = &s[lenword];
		i++;
	}
	lstword[i] = NULL;
	return (lstword);
}

char	**ft_split(char const *s, char c)
{
	char	**lstwords;
	size_t	words;

	if (s == NULL)
		return (NULL);
	words = ft_wordcount((char *) s, c);
	lstwords = (char **) malloc(sizeof(char *) * (words + 1));
	if (!lstwords)
		return (NULL);
	lstwords = ft_write_split(lstwords, s, c);
	return (lstwords);
}
