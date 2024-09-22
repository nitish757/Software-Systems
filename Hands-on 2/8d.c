/*
============================================================================
Name : 8d.c
Author : Nitish Mahapatre
Description : Write a separate program using signal system call to catch the following signals.
                d. SIGALRM (use alarm system call)
Date: 19 Sep, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

void sigalrm_handler(int signum) {
    printf("Caught signal SIGALRM: Timer expired\n");
}
void main(){
    signal(SIGALRM, sigalrm_handler);
    printf("Setting an alarm for 3 seconds using alarm()...\n");
    alarm(3);
    sleep(4);
}
/*======================================================
Output:
Setting an alarm for 3 seconds using alarm()...
Caught signal SIGALRM: Timer expired
=======================================================*/
