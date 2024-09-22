/*
============================================================================
Name : 10b.c
Author : Nitish Mahapatre
Description : Write a separate program using sigaction system call to catch the following signals.
                b. SIGINT
Date: 19 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sigint_handler(int signum) {
    printf("\nCaught signal SIGINT: Interrupt from keyboard (Ctrl+C)\n");
}

void main(){
    struct sigaction sa;

    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);    

    printf("Press Ctrl+C to trigger SIGINT\n");

    sleep(5);

}
/*===========================================
Output:
Press Ctrl+C to trigger SIGINT
^C
Caught signal SIGINT: Interrupt from keyboard (Ctrl+C)
=============================================*/