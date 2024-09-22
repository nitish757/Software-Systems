/*
============================================================================
Name : 13b.c
Author : Nitish Mahapatre
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
                will send the signal (using kill system call). Find out whether the first program is able to catch
                the signal or not.
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void main(){
    pid_t pid;

    printf("Enter the PID of Program 1: ");
    scanf("%d", &pid);

    printf("Sending SIGUSR1 signal to process %d...\n", pid);
    kill(pid, SIGUSR1);

    printf("Sending SIGSTOP signal to process %d...\n", pid);
    kill(pid, SIGSTOP);

    sleep(3); 
    printf("Sending SIGCONT signal to process %d...\n", pid);
    kill(pid, SIGCONT);
}
/*================================================
Output:
Enter the PID of Program 1: 5427
Sending SIGUSR1 signal to process 5427...
Sending SIGSTOP signal to process 5427...
Sending SIGCONT signal to process 5427...
=================================================*/