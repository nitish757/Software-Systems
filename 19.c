/*============================================================================
Name : 19.c
Author : Nitish Mahapatre
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 30th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc":"=A"(dst));
}
int main(){
    int i, nano;
    unsigned long long int start, end;
    start=rdtsc();
    for(i=0;i<=10000;i++){
        getpid();
    }
    end=rdtsc();
    nano= (end-start)/2.09;
    printf("The function takes %d nano sec\n", nano);
    return 0;
}
/*Output:
./a.out
The function takes 32927207 nano sec
*/