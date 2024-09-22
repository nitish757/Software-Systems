/*
============================================================================
Name : 8g.c
Author : Nitish Mahapatre
Description : Write a separate program using signal system call to catch the following signals.
                g. SIGPROF (use setitimer system call)
Date: 19 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sigprof_handler(int signum) {
    printf("Caught signal SIGPROF: Profiling timer expired\n");
}

void main(){
    signal(SIGPROF, sigprof_handler);

    struct itimerval timer;
    timer.it_value.tv_sec = 2;   
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_PROF, &timer, NULL);
    printf("Setting a profiling timer for 2 seconds using setitimer()...\n");
    while(1);
}
/*=================================================
Output:
Setting a profiling timer for 2 seconds using setitimer()...
Caught signal SIGPROF: Profiling timer expired
====================================================*/