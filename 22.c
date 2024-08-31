/*============================================================== 
Name : 22.c
Author : Nitish Mahapatre
Description:Write a program, open a file, call fork, and then write to the file by both the child as well as the
            parent processes. Check output of the file.
Date: 30th Aug, 2024
=================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
void main(){
    int pid=fork();
    int fd=open("file22.txt", O_RDWR|O_CREAT|O_APPEND,0644);
    if(fd==-1){
        perror("Can't open file\n");
        exit(0);
    }
    if(pid<0){
        perror("Fork failed!\n");
        exit(0);
    }
    else if(pid==0){
        const char* cData="Child Data\n";
        if(write(fd,cData,strlen(cData))==-1){
            perror("child write error\n");
            close(fd);
            exit(0);
        }
        printf("Child has Written\n");
    }
    else{
        wait(NULL);
        const char* pData="Parent Data\n";
        if(write(fd,pData,strlen(pData))==-1){
            perror("parent write error\n");
            close(fd);
            exit(0);
        }
        printf("Parent has Written\n");
    }
    close(fd);
}
/*=======================================
Output:
./a.out
Child has Written
Parent has Written
*/