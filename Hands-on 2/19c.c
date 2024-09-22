/*
============================================================================
Name : 19c.c
Author : Nitish Mahapatre
Description : Create a FIFO file by
                c. mknod system call
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void main() {
    const char *fifoPath = "19cfifo";
    
    if (mknod(fifoPath, S_IFIFO | 0666, 0) < 0) {
        perror("mknod failed");
        exit(1);
    }

    printf("FIFO created using mknod: %s\n", fifoPath);
}
/*=========================================
Output:
FIFO created using mknod: 19cfifo
===========================================*/