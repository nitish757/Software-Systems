/*
============================================================================
Name : 7.c
Author : Nitish Mahapatre
Description : Write a simple program to print the created thread ids.
Date: 18 Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

void thread_func(void){
    printf("Thread id is %lu\n", pthread_self());
}

void main(){
    pthread_t tid;
    int tnum[3];
    if(pthread_create(&tid, NULL, (void *) thread_func, NULL) !=0){
        perror("Thread Creation error\n");
        exit(1);
    }
    
    pthread_join(tid, NULL);

}
/*========================================================
Output:
Thread id is 140694054237888
==========================================================
*/