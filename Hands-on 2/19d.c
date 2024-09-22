/*
============================================================================
Name : 19d.c
Author : Nitish Mahapatre
Description : Create a FIFO file by
                d. mkfifo library function
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdlib.h>

void main() {
    const char *fifoPath = "19d_fifo";

    if (mkfifo(fifoPath, 0666) < 0) {
        perror("mkfifo failed");
        exit(1);
    }

    printf("FIFO created using mkfifo: %s\n", fifoPath);
}
/*================================
Output:
FIFO created using mkfifo: 19d_fifo
==================================*/