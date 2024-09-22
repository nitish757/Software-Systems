/*
============================================================================
Name : 10c.c
Author : Nitish Mahapatre
Description : Write a separate program using sigaction system call to catch the following signals.
                c. SIGFPE
Date: 19 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sigfpe_handler(int signum) {
    printf("Caught signal SIGFPE: Floating Point Exception (e.g., division by zero)\n");
    exit(1); 
}

void main(){
    struct sigaction sa;

    sa.sa_handler = sigfpe_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGFPE, &sa, NULL);     

    printf("Running code tp trigger SIGFPE signal\n");
    int i=10/0;

    sleep(5);


}
/*===========================================
Output:
Running code tp trigger SIGFPE signal
Caught signal SIGFPE: Floating Point Exception (e.g., division by zero)
=============================================*/