/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pquintan <pquintan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:03:56 by agusheredia       #+#    #+#             */
/*   Updated: 2024/05/13 14:00:19 by pquintan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//print quick chat gpt
void	print_array(char **array)
{
    char**rowPtr = array;
    char *colPtr;

    while (*rowPtr != NULL) {
        colPtr = *rowPtr;
        
        while (*colPtr != '\0') {
            printf("%c ", *colPtr);
            colPtr++;
        }

        printf("\n");
        rowPtr++;
    }
}
