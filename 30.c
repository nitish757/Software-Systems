/*============================================================== 
Name : 30.c
Author : Nitish Mahapatre
Description: Write a program to run a script at a specific time using a Daemon process.
Date: 31th Aug, 2024
=================================================================
*/
#include<unistd.h>
#include<sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
void main(){
    if(!fork()){
        setsid();
        chdir("/");
        umask(0);
        while(1){
            sleep(4);
            printf("child pid: %d\n", getpid());
            printf("Daemon process is running......\n");
        }
    }
    else
        exit(0);
}
/*=====================================
Output:
child pid: 4587
Daemon process is running......
child pid: 4587
Daemon process is running......
child pid: 4587
Daemon process is running......
child pid: 4587
Daemon process is running......
child pid: 4587
Daemon process is running......*/