/*
============================================================================
Name : 11.c
Author : Nitish Mahapatre
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
                use sigaction system call.
Date: 19 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void reset_sigint_handler(int signum) {
    printf("\nSIGINT received! Default action restored. Exiting...\n");
    exit(1);
}

int main() {
    struct sigaction sa;

    printf("Ignoring SIGINT (Ctrl+C) for 10 seconds...\n");
    sa.sa_handler = SIG_IGN; 
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL); 

    sleep(10);

    printf("\nResetting SIGINT to default behavior\n");
    sa.sa_handler = reset_sigint_handler; 
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL); 

    printf("Now, Ctrl+C will terminate the process if not pressed, program will exit normally...\n");
    sleep(10);

    printf("Program exiting normally.\n");
    return 0;
}
/*===========================================
Output:
Ignoring SIGINT (Ctrl+C) for 10 seconds...
^C^C^C^C^C^C^C^C^C^C^C^C
^C
^C

Resetting SIGINT to default behavior
Now, Ctrl+C will terminate the process if not pressed, program will exit normally...
^C
SIGINT received! Default action restored. Exiting...
=============================================*/