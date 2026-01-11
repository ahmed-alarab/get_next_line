/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmad <ahmad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 14:57:48 by ahmad             #+#    #+#             */
/*   Updated: 2026/01/11 20:45:48 by ahmad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "get_next_line.h"

char *read_to_stash(int fd, char *stash)
{
    char *bf;
    int read_bytes;

    read_bytes = 1;
    bf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    while (!(ft_strchr(stash, '\n')) && read_bytes != 0)
    {

        read_bytes = read(fd, bf, BUFFER_SIZE);
        if (read_bytes == -1)
        {
            free(bf);
            free(stash);
            return NULL;
        }
        bf[read_bytes] = '\0';
        stash = ft_strjoin(stash, bf);
    }
    free(bf);
    return stash;
}

char *get_the_line(char *line)
{
    int count;
    char *new_line;

    count = 0;
    if (line == NULL || line[0] == '\0')
        return NULL;
    while (line[count] != '\n' && line[count] != '\0')
        count++;
    new_line = malloc(sizeof(char) * (count + 2));
    count = 0;
    while (line[count] != '\n' && line[count] != '\0')
    {
        new_line[count] = line[count];
        count++;
    }
    if (line[count] == '\n')
    {
        new_line[count] = line[count];
        count++;
    }
    new_line[count] = '\0';
    return new_line;
}

char *update_stash(char *stash)
{
    int i;
    int j;
    char *new_stash;

    i = 0;
    j = 0;
    if (!stash)
        return NULL;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return NULL;
    }
    i++;
    new_stash = malloc(sizeof(char) * (ft_strlen(stash + i) + 1));
    if (!new_stash)
        return NULL;
    while (stash[i])
        new_stash[j++] = stash[i++];
    new_stash[j] = '\0';
    free(stash);
    return new_stash;
}

char *get_next_line(int fd)
{
    static char *stash;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    stash = read_to_stash(fd, stash);
    if (!stash)
        return (NULL);

    line = get_the_line(stash);

    stash = update_stash(stash);

    return (line);
}