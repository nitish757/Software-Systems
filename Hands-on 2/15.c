/*
============================================================================
Name : 15.c
Author : Nitish Mahapatre
Description : Write a simple program to send some data from parent to the child process.
Date: 21 Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void main() {
    int fd[2];
    pid_t pid;
    char write_msg[] = "Parent says Hello!";
    char read_msg[100];

    if (pipe(fd) == -1) {
        perror("pipe failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(2);
    }

    if (pid > 0) {
        close(fd[0]);

        write(fd[1], write_msg, strlen(write_msg) + 1); 
        close(fd[1]); 

        wait(NULL);
    }
    else {
        close(fd[1]); 

        read(fd[0], read_msg, sizeof(read_msg));
        printf("Message to Child process: %s\n", read_msg);

        close(fd[0]);
    }

}
/*=======================================
Output:
Message to Child process: Parent says Hello!
=========================================*/