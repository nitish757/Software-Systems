/*
============================================================================
Name : 6.c
Author : Nitish Mahapatre
Description :Write a simple program to create three threads.
Date: 18 Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

void thread_func(void * arg){
    int tnum=*((int*)arg);
    printf("Thread %d is running!\n", tnum);
    pthread_exit(NULL);
}

void main(){
    pthread_t tid[3];
    int tnum[3];
    for(int i=0;i<3;i++){
        tnum[i]=i+1;
        if(pthread_create(&tid[i], NULL, (void *) thread_func, &tnum[i]) !=0){
            perror("Thread Creation error\n");
            exit(1);
        }

    }
    
    for(int i=0;i<3;i++){
        pthread_join(tid[i], NULL);
    }

    printf("All 3 threads are finished!\n");
}
/*======================================
Output:
Thread 1 is running!
Thread 2 is running!
Thread 3 is running!
All 3 threads are finished!
=======================================*/