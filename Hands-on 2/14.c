/*
============================================================================
Name : 14.c
Author : Nitish Mahapatre
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
                the monitor.
Date: 21 Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main() {
    int fd[2]; 
    char write_msg[] = "Program 14 says Hello!"; 
    char read_msg[100]; 

    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    write(fd[1], write_msg, strlen(write_msg) + 1);

    read(fd[0], read_msg, sizeof(read_msg));

    printf("Message read from the pipe: %s\n", read_msg);

    close(fd[0]); 
    close(fd[1]); 
}
/*================================================
Output:
Message read from the pipe: Program 14 says Hello!
==================================================
*/