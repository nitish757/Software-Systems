/*
============================================================================
Name : 16.c
Author : Nitish Mahapatre
Description : Write a program to send and receive data from parent to child vice versa. Use two way
communication.
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

void main() {
    int ptoc[2];
    int ctop[2];
    pid_t pid;
    char p_msg[] = "Hello from parent!";
    char c_msg[] = "Hello from child!";
    char read_msg[100];

    if (pipe(ptoc) == -1 || pipe(ctop) == -1) {
        perror("pipe failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork failed");
        exit(2);
    }

    if (pid > 0) {
        close(ptoc[0]);
        close(ctop[1]);

        write(ptoc[1], p_msg, strlen(p_msg) + 1); 
        close(ptoc[1]); 

        read(ctop[0], read_msg, sizeof(read_msg));
        printf("Parent received: %s\n", read_msg);

        close(ctop[0]);
    }
    else {
        close(ptoc[1]);  
        close(ctop[0]); 

        read(ptoc[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);

        write(ctop[1], c_msg, strlen(c_msg) + 1);  
        close(ctop[1]);

        close(ptoc[0]);
    }

}
/*==================================================
Output:
Child received: Hello from parent!
Parent received: Hello from child!
===================================================*/