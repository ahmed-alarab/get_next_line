/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad <ahmad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:30:16 by ahmad             #+#    #+#             */
/*   Updated: 2026/01/11 19:20:53 by ahmad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "stdlib.h"

size_t ft_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *str_join(char *s1, char *s2)
{
    char *join;
    int i;
    int j;

    i = 0;
    j = 0;
    if (!s1 && !s2)
        return NULL;
    if (!s1)
    {
        join = malloc(sizeof(char) * (str_len(s2) + 1));
        while (s2[i])
            join[i] = s2[i++];
        join[i] = '\0';
        return join;
    }
    if (!s2)
    {
        join = malloc(sizeof(char) * (str_len(s1) + 1));
        while (s1[i])
            join[i] = s1[i++];
        join[i] = '\0';
        free(s1);
        return join;
    }
    join = malloc(sizeof(char) * (str_len(s1) + str_len(s2) + 1));
    while (s1[i])
        join[i] = s1[i++];
    while (s2[j])
        join[i++] = s2[j++];

    join[i] = '\0';
    free(s1);
    return (join);
}

char* ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    if (str == NULL)
        return NULL;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return &str[i];
        i++;
    }
    if (str[i] == c)
        return &str[i];
    return NULL;
}