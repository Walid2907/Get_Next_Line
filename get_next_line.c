/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:04:49 by wkerdad           #+#    #+#             */
/*   Updated: 2025/11/21 22:24:21 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char *read_until_newline(int fd, char *remainder)
{
    char buffer[BUFFER_SIZE + 1];
    ssize_t bytes_read;

    while (!ft_strchr(remainder, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';
        remainder = ft_strjoin(remainder, buffer);
        if (!remainder)
            return NULL;
    }
    return remainder;
}

static char *extract_line(char *remainder)
{
    size_t i = 0;
    if (!remainder || remainder[0] == '\0')
        return NULL;
    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (remainder[i] == '\n')
        i++;
    return (ft_substr(remainder, 0, i));
}

static char *update_remainder_after_line(char *remainder)
{
    size_t i = 0;
    size_t len;
    if (remainder == NULL)
        return NULL;
    while (remainder[i] && remainder[i] != '\n')
        i++;
    if (!remainder[i])
    {
        free(remainder);
        return NULL;
    }
    i++;
    len = ft_strlen(remainder + i);
    char *new = ft_substr(remainder, i, len);
    free(remainder);
    return new;
}

char *get_next_line(int fd)
{
    static char *remainder;
    char *line;

    remainder = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    remainder = read_until_newline(fd, remainder);
    if (remainder == NULL)
        return NULL;
    line = extract_line(remainder);
    remainder = update_remainder_after_line(remainder);
    return line;
}

int main ()
{
    int fd;
    fd = open("example.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s \n",line);
        free(line);
    }
    close(fd);
}
