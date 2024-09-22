/*
============================================================================
Name : 17c.c
Author : Nitish Mahapatre
Description : Write a program to execute ls -l | wc.
                c. use fcntl
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void main() 
{
    int fd[2];
    pipe(fd);

    if(!fork()){
        close(1);
        close(fd[0]);
        fcntl(fd[1],F_DUPFD,0);
        execlp("ls", "ls", "-l", (char*)NULL);
    }
    else{
        close(0);
        close(fd[1]);
        fcntl(fd[0],F_DUPFD,0);
        execlp("wc", "wc", (char*)NULL);
    }
}
/*==========================================
Output:
     34     299    2375
============================================*/