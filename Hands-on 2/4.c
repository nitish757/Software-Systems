/*
============================================================================
Name : 4.c
Author : Nitish Mahapatre
Description :Write a program to measure how much time is taken to execute 100 getppid ( )
             system call. Use time stamp counter.
Date: 12th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A"(dst));
}
void main(){
    int i, cc;
    unsigned long long int start, end;
    start=rdtsc();
    for(i=0;i<=100;i++){
        getppid();
    }
    end=rdtsc();
    cc= end-start;
    printf("The function takes %d cycles\n", cc);
}

/*====================================
Output:
The function takes 709309 cycles
======================================*/