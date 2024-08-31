/*============================================================================
Name : 16a.c
Author : Nitish Mahapatre
Description : Write a program to perform mandatory locking.
                    a. Implement write lock
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<sys/file.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

void main(){
    int fd=open("file16a.txt", O_RDWR|O_CREAT, 0664);

    if(fd==-1){
        perror("File can't be open\n");
        exit(0);
    }

    struct flock lock;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_type=F_WRLCK;

    if(fcntl(fd,F_SETLK, &lock)==-1){
        if(errno==EACCES|| errno==EAGAIN)
            perror("Lock is aleary acquired or does not support\n");
        else
            perror("Lock Acquired failed\n");
        close(fd);
        exit(0);
    }

    printf("Wirte lock acquired, press enter to release\n");
    getchar();

    lock.l_type=F_UNLCK;
    if(fcntl(fd,F_SETLK, &lock)==-1)
        perror("Cannot release write lock\n");
    else
        printf("Write Lock released\n");
    
    close(fd);
}

/*==============================================
Output:
Wirte lock acquired, press enter to release

Write Lock released
================================================*/