/*
============================================================================
Name : 8f.c
Author : Nitish Mahapatre
Description : Write a separate program using signal system call to catch the following signals.
                f. SIGVTALRM (use setitimer system call)
Date: 19 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<sys/time.h>

void sigvtalrm_handler(int signum) {
    printf("Caught signal SIGVTALRM: Virtual timer expired\n");
}
void main(){
    signal(SIGVTALRM, sigvtalrm_handler);
    struct itimerval timer;
    timer.it_value.tv_sec = 2;    
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0; 
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);
    printf("Setting a virtual timer for 2 seconds using setitimer()...\n");
    while(1);
}
/*===================================================
Output:
Setting a virtual timer for 2 seconds using setitimer()...
Caught signal SIGVTALRM: Virtual timer expired
=====================================================*/