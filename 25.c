/*============================================================== 
Name : 25.c
Author : Nitish Mahapatre
Description: Write a program to create three child processes. The parent should wait for a particular child (use
            waitpid system call).
Date: 30th Aug, 2024
=================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

void main(){
    pid_t pid1,pid2,pid3;

    pid1=fork();
    if(pid1<0){
        perror("Fork for child 1 failed!\n");
        exit(0);
    }
    else if (pid1 == 0) {
        printf("Child 1 (PID=%d) is running\n", getpid());
        sleep(2); 
        printf("Child 1 (PID=%d) is exiting\n", getpid());
        exit(0); 
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("Fork for child 2 failed!\n");
        exit(0);
    }
    else if (pid2 == 0) {
        printf("Child 2 (PID=%d) is running\n", getpid());
        sleep(4); 
        printf("Child 2 (PID=%d) is exiting\n", getpid());
        exit(0); 
    }

    pid3 = fork();
    if (pid3 < 0) {
        perror("Fork for child 3 failed!\n");
        exit(0);
    }
    else if (pid3 == 0) {
        printf("Child 3 (PID=%d) is running\n", getpid());
        sleep(6);
        printf("Child 3 (PID=%d) is exiting\n", getpid());
        exit(0);
    }

    int status;
    printf("Parent (PID=%d) is waiting for Child 2 (PID=%d) to exit\n", getpid(), pid2);
    waitpid(pid2, &status, 0);

    printf("Child 2 has exited\n");
    printf("Parent process (PID=%d) is done.\n", getpid());
}
/*===================================================
Output:
./a.out
Child 1 (PID=22453) is running
Parent (PID=22452) is waiting for Child 2 (PID=22454) to exit
Child 2 (PID=22454) is running
Child 3 (PID=22455) is running
Child 1 (PID=22453) is exiting
Child 2 (PID=22454) is exiting
Child 2 has exited with status 3
Parent process (PID=22452) is done.
Child 3 (PID=22455) is exiting*/