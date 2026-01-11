/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad <ahmad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:30:16 by ahmad             #+#    #+#             */
/*   Updated: 2026/01/11 20:34:19 by ahmad            ###   ########.fr       */
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

char *ft_strjoin(char *s1, char *s2)
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
        join = malloc(sizeof(char) * (ft_strlen(s2) + 1));
        if (join == NULL)
            return NULL;
        while (s2[i])
        {
            join[i] = s2[i];
            i++;
        }
        join[i] = '\0';
        return join;
    }
    if (!s2)
    {
        join = malloc(sizeof(char) * (ft_strlen(s1) + 1));
        if (join == NULL)
            return NULL;
        while (s1[i])
        {
            join[i] = s1[i];
            i++;
        }
        join[i] = '\0';
        free(s1);
        return join;
    }
    join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (join == NULL)
        return NULL;
    while (s1[i])
    {
        join[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        join[i] = s2[j];
        i++;
        j++;
    }

    join[i] = '\0';
    free(s1);
    return (join);
}

char *ft_strchr(char *str, char c)
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