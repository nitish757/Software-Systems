/*
============================================================================
Name : 8c.c
Author : Nitish Mahapatre
Description : Write a separate program using signal system call to catch the following signals.
                c. SIGFPE
Date: 19 Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

void sigfpe_handler(int signum) {
    printf("Caught signal SIGFPE: Floating point exception\n");
    exit(1);
}
void main(){
    signal(SIGFPE, sigfpe_handler);
    int x = 1 / 0; 
}

/*======================================================
Output:
Caught signal SIGFPE: Floating point exception
=======================================================*/