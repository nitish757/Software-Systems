/*
============================================================================
Name : 8a.c
Author : Nitish Mahapatre
Description : Write a separate program using signal system call to catch the following signals.
                a. SIGSEGV
Date: 19 Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sigsegv_handler(int signum) {
    printf("Caught signal SIGSEGV: Segmentation fault\n");
    exit(1);
}

void main(){
    signal(SIGSEGV, sigsegv_handler);
    int* p=NULL;
    *p=30;
}
/*========================================================
Output:
Caught signal SIGSEGV: Segmentation fault
==========================================================
*/