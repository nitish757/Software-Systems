/*
============================================================================
Name : 20a.c
Author : Nitish Mahapatre
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void main() {
    int fd;
    char buf[80];

    fd=open("myfifo1", O_RDONLY);
    read(fd, buf, sizeof(buf));
    printf("The text from FIFO: %s\n", buf);  
    close(fd);
}
/*=====================================
Output:
The text from FIFO: Message from program 2
======================================*/
