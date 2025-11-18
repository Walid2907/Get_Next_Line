/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkerdad <wkerdad@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 18:01:19 by wkerdad           #+#    #+#             */
/*   Updated: 2025/11/18 18:36:48 by wkerdad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>     // open(), O_CREAT, O_WRONLY, O_RDONLY
#include <unistd.h>    // read(), write(), close()
#include <stdlib.h>    // exit()
#include <string.h>    // strlen()
#include <stdio.h>
int main(void)
{
    int fd;
    ssize_t bytes_read = 0;
    int i = 0;
    char *str = "test my name is walid \nb ";
    printf("%ld\n",strlen(str));
    char *buffer = malloc(strlen(str) + 1);
    if(buffer == NULL)
        return 0;


    fd = open("example.txt", O_CREAT | O_WRONLY , 0644);
    if (fd < 0)
        return 1;

    write(fd, str, strlen(str));
    close(fd);
    
    fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return 1;
    while(i < (int)strlen(str))
    {
        bytes_read += read(fd, &buffer[i], 1)
        
            printf("wslna l l3ayba\n");
        printf("%s\n",buffer);
        i++;
    }
    printf("%ld",bytes_read);
    if (bytes_read < 0)
        return 1;
    buffer[bytes_read] = '\0'; 
    write(1, "File content:\n", 14);
    write(1, buffer, bytes_read);

    close(fd);

    return 0;
}
