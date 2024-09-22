/*
============================================================================
Name : 17b.c
Author : Nitish Mahapatre
Description : Write a program to execute ls -l | wc.
                b. use dup2
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
    pipe(fd);

    if(!fork()){
        close(fd[0]);
        dup2(fd[1],1);
        execlp("ls", "ls", "-l", (char*)NULL);
    }
    else{
        close(fd[1]);
        dup2(fd[0],0);
        execlp("wc", "wc", (char*)NULL);
    }
}
/*=============================
Output:
     34     299    2375
===============================*/