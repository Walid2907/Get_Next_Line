/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:59:51 by wkerdad           #+#    #+#             */
/*   Updated: 2025/11/25 17:14:44 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*helper(char *remainder, char *buffer, int fd)
{
	ssize_t	bytes_read;

	while (!ft_strchr(remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(remainder);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		remainder = ft_strjoin(remainder, buffer);
		if (!remainder)
		{
			return (NULL);
		}
	}
	return (remainder);
}

static char	*read_until_newline(int fd, char *remainder)
{
	char	*buffer;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	if (remainder == NULL)
		remainder = ft_strdup("");
	if (!remainder)
	{
		free(buffer);
		return (NULL);
	}
	remainder = helper(remainder, buffer, fd);
	if (remainder == NULL)
	{
		free(buffer);
		return (NULL);
	}
	free(buffer);
	return (remainder);
}

static char	*extract_line(char *remainder)
{
	size_t	i;

	i = 0;
	if (!remainder || remainder[0] == '\0')
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (remainder[i] == '\n')
		i++;
	return (ft_substr(remainder, 0, i));
}

static char	*update_remainder_after_line(char *remainder)
{
	size_t	i;
	size_t	len;
	char	*new;

	i = 0;
	if (remainder == NULL)
		return (NULL);
	while (remainder[i] && remainder[i] != '\n')
		i++;
	if (!remainder[i])
	{
		free(remainder);
		return (NULL);
	}
	i++;
	len = ft_strlen(remainder + i);
	new = ft_substr(remainder, i, len);
	free(remainder);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*remainder[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	remainder[fd] = read_until_newline(fd, remainder[fd]);
	if (remainder[fd] == NULL)
		return (NULL);
	line = extract_line(remainder[fd]);
	remainder[fd] = update_remainder_after_line(remainder[fd]);
	if (remainder[fd] == NULL || *remainder[fd] == '\0')
	{
		free(remainder[fd]);
		remainder[fd] = NULL;
		return (line);
	}
	return (line);
}
