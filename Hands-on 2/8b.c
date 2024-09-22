/*
============================================================================
Name : 8b.c
Author : Nitish Mahapatre
Description : Write a separate program using signal system call to catch the following signals.
                b. SIGINT
Date: 19 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("\nCaught signal SIGINT: Interrupt (Ctrl+C)\n");
}
void main(){
    signal(SIGINT, sigint_handler);
    printf("Press Ctrl+C to trigger SIGINT...\n");
    sleep(2);
}
/*======================================================
Output:
Press Ctrl+C to trigger SIGINT...
^C
Caught signal SIGINT: Interrupt (Ctrl+C)
=======================================================*/