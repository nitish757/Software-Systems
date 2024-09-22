/*
============================================================================
Name : 12.c
Author : Nitish Mahapatre
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
                the parent process from the child process.
Date: 19 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>

void main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process created with PID: %d\n", getpid());

        printf("Child process is killing parent process with PID: %d\n", getppid());
        kill(getppid(), SIGKILL);

        printf("Child process is now an orphan and will sleep for 10 seconds.\n");
        sleep(10);

        printf("Child process (orphan) finished.\n");
    }
    else {
        printf("Parent process (PID: %d) is waiting for a while before being killed...\n", getpid());
        sleep(5);
        printf("Parent process finished.\n");
    }
}
/*=================================================
Output:
Parent process (PID: 6109) is waiting for a while before being killed...
Child process created with PID: 6110
Child process is killing parent process with PID: 6109
Child process is now an orphan and will sleep for 10 seconds.
Killed
Child process (orphan) finished.
==================================================*/