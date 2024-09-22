/*
============================================================================
Name : 8e.c
Author : Nitish Mahapatre
Description : Write a separate program using signal system call to catch the following signals.
                e. SIGALRM (use setitimer system call)
Date: 19 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<sys/time.h>

void sigalrm_handler(int signum) {
    printf("Caught signal SIGALRM: Real timer expired\n");
}
void main(){
    signal(SIGALRM, sigalrm_handler);
    struct itimerval timer;
    timer.it_value.tv_sec = 2;    
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; 
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    printf("Setting alarm for 2 seconds using setitimer()...\n");
    sleep(4);
}
/*=============================================
Output:
Setting alarm for 2 seconds using setitimer()...
Caught signal SIGALRM: Real timer expired
===============================================
*/