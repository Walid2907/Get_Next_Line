/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 19:04:45 by wkerdad           #+#    #+#             */
/*   Updated: 2025/11/21 21:55:45 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		i;
	size_t		new_len;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen((s + start));
	if (len > new_len)
		sub_str = malloc(new_len + 1);
	else
		sub_str = malloc(len + 1);
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		join_len;
	int		i;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	join_len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(join_len + 1);
	if (str == NULL)
		return (NULL);
	while (i < join_len && *s1 != '\0')
		str[i++] = *(s1++);
	while (i < join_len && *s2 != '\0')
		str[i++] = *(s2++);
	str[i] = '\0';
	return (str);
}
char	*ft_strchr(const char *str, int c)
{
	unsigned char	*s;

	if (str == NULL)
		return (NULL);
	s = (unsigned char *)str;
	if (c == '\0')
		return ((char *)(s + ft_strlen(str)));
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}
char	*ft_strdup(const char *s)
{
	char	*str;
	char	*new_str;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	len = ft_strlen(str);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (*str != '\0')
	{
		*(new_str + i) = *(str);
		str++;
		i++;
	}
	*(new_str + i) = '\0';
	return ((char *)new_str);
}
