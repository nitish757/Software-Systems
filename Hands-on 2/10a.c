/*
============================================================================
Name : 10a.c
Author : Nitish Mahapatre
Description : Write a separate program using sigaction system call to catch the following signals.
                a. SIGSEGV
Date: 19 Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void sigsegv_handler(int signum) {
    printf("Caught signal SIGSEGV: Segmentation Fault\n");
    exit(1);
}

void main(){
    struct sigaction sa;
    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, NULL);

    printf("Running segment fault code!\n");
    int* p=NULL;
    *p=30;
    sleep(5);
    printf("Wait for Segmentation fault to trigger SIGSEGV\n");
}
/*===========================================
Output:
Running segment fault code!
Caught signal SIGSEGV: Segmentation Fault
=============================================*/