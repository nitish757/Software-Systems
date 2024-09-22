/*
============================================================================
Name : 13a.c
Author : Nitish Mahapatre
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
                will send the signal (using kill system call). Find out whether the first program is able to catch
                the signal or not.
Date: 21 Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigusr1_handler(int signum) {
    printf("Caught signal SIGUSR1\n");
}

void main() {
    signal(SIGUSR1, sigusr1_handler);

    printf("Program 1 (PID: %d) is waiting for signals...\n", getpid());

    while (1) {
        pause();  
    }

}
/*=============================================
Output:
Program 1 (PID: 5427) is waiting for signals...

[2]+  Stopped                 ./a.out
Caught signal SIGUSR1
^C
===================================================*/
