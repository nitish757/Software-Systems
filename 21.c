/*============================================================== 
Name : 21.c
Author : Nitish Mahapatre
Description:Write a program, call fork and print the parent and child process id.
Date: 30th Aug, 2024
=================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
void main(){
    int pid=fork();
    if(pid<0){
            perror("Fork failed!\n");
            exit(0);
    }
    else if(pid==0)
        printf("Child process PID is %d and Parent process PID is%d\n",getpid(),getppid());
    else
        printf("Parent process PID is %d and Child process PID is%d\n",getpid(),pid);
}
/*=====================================
Output:
./a.out
Parent process PID is 16220 and Child process PID is16222
Child process PID is 16222 and Parent process PID is16220*/