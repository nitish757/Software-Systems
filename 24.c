/*============================================================== 
Name : 24.c
Author : Nitish Mahapatre
Description: Write a program to create an orphan process.
Date: 30th Aug, 2024
=================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<signal.h>
void main(){
    pid_t pid=fork();
    if(pid<0){
        perror("Fork Failed!\n");
        exit(0);
    }
    if(pid==0){
        printf("Child process(PID=%d) going to slepp for 20sec\n",getpid());
        fflush(stdout);
        sleep(20);
        printf("Orphan Child process pid=%d running\n",getpid());
        fflush(stdout);
        
    }
    else{
        sleep(1);
        printf("Parent process(PID=%d) Running\n",getpid());
        fflush(stdout);
    }
}
/*===============================================
Output:
Child process(PID=20127) going to slepp for 20sec
Parent process(PID=20126) Running
Orphan Child process pid=20127 running*/