/*============================================================== 
Name : 23.c
Author : Nitish Mahapatre
Description: Write a program to create a Zombie state of the running program.
Date: 30th Aug, 2024
=================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <time.h>
void main(){
    int pid=fork();
    if(pid<0){
        perror("Fork failed!\n");
        exit(0);
    }
    if(pid==0){
        printf("Child Process(pid=%d) is terminating......\n",getpid());
    }
    else{
        printf("Parent(PID=%d) going to sleep for 30 sec\n",getpid());
        sleep(30);
        printf("Parent wakes up and calling wait() to terminate Zombie process\n");
        wait(NULL);
    }
}
/*=========================================
Output:
./a.out
Parent(PID=18634) going to sleep for 30 sec
Child Process(pid=18635) is terminating......
Parent wakes up and calling wait() to terminate Zombie process
==========================================*/