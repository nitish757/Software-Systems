/*
============================================================================
Name : 9.c
Author : Nitish Mahapatre
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
              signal - Use signal system call.
Date: 19 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void main() {
    printf("Ignoring SIGINT (Ctrl+C) for 10 seconds...\n");
    signal(SIGINT, SIG_IGN);

    sleep(10);

    printf("\nResetting SIGINT to default behavior (Ctrl+C will terminate the program)...\n");
    signal(SIGINT, SIG_DFL); 

    sleep(10);

    printf("\nProgram exiting normally.\n");
}
/*================================================
Output:
Ignoring SIGINT (Ctrl+C) for 10 seconds...
^C^C^C^C^C^C^C^C^C
Resetting SIGINT to default behavior (Ctrl+C will terminate the program)...
^C
=================================================
*/