/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pestmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:07:44 by kweihman          #+#    #+#             */
/*   Updated: 2024/09/09 11:07:44 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h> // for fork(), pipe(), read(), write(), close()
#include <stdio.h> // for printf(), scanf()
#include <sys/wait.h> // for wait()
#include <sys/types.h> // for pid_t
#include <sys/stat.h> // for mkfifo()
#include <errno.h> // for errno
#include <fcntl.h> // for open()

int main()
{
    if (mkfifo("fifo", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Error creating FIFO\n");
            return 1;
        }
    }
    printf("Opening FIFO\n");
    int fd = open("fifo", O_WRONLY);
    printf("Opened\n");
    int x = 1633837824;
    if (write(fd, &x, sizeof(x)) == -1)
    {
        printf("Error writing to FIFO\n");
        return 2;
    }
    printf("Written\n");
    close(fd);
    return 0;
}