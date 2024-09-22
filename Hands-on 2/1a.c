/*
============================================================================
Name : 1a.c
Author : Nitish Mahapatre
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
              10micro second
                a. ITIMER_REAL
Date: 12th Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<signal.h>

void handle_sigalrm(int sig){
    static int i=1;
    printf("ITIMER_REAL timer expired %d time\n", i);
    i++;
}

void main(){
    struct itimerval timer;

    signal(SIGALRM, handle_sigalrm);

    timer.it_value.tv_sec=10;
    timer.it_value.tv_usec=10;

    timer.it_interval.tv_sec=10;
    timer.it_interval.tv_usec=10;

    setitimer(ITIMER_REAL, &timer, NULL);

    while(1){

    }
}
/*========================================
Output:
ITIMER_REAL timer expired 1 time
ITIMER_REAL timer expired 2 time
ITIMER_REAL timer expired 3 time
===========================================*/