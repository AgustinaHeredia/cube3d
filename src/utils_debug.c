/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agusheredia <agusheredia@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:03:56 by agusheredia       #+#    #+#             */
/*   Updated: 2024/05/06 21:04:59 by agusheredia      ###   ########.fr       */
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