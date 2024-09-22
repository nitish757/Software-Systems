/*
============================================================================
Name : 23.c
Author : Nitish Mahapatre
Description : Write a program to print the maximum number of files can be opened within a process and
                size of a pipe (circular buffer).
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

void main() {
    struct rlimit limit;
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("getrlimit failed");
        exit(1);
    }
    
    printf("Maximum number of open files: Soft limit = %lu, Hard limit = %lu\n", limit.rlim_cur, limit.rlim_max);

    int pipefd[2];
    pipe(pipefd);

    printf("Pipe created with read fd = %d and write fd = %d\n", pipefd[0], pipefd[1]);

    close(pipefd[0]);
    close(pipefd[1]);

}
/*=========================================
Output:
Maximum number of open files: Soft limit = 1048576, Hard limit = 1048576
Pipe created with read fd = 3 and write fd = 4
==========================================*/