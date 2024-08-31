/*============================================================================
Name : 16b.c
Author : Nitish Mahapatre
Description : Write a program to perform mandatory locking.
                    b. Implement read lock
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
    int fd=open("file16b.txt", O_RDONLY);

    if(fd==-1){
        perror("File can't be open\n");
        exit(0);
    }

    struct flock lock;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;
    lock.l_type=F_RDLCK;

    if(fcntl(fd,F_SETLK, &lock)==-1){
        if(errno==EACCES|| errno==EAGAIN)
            perror("Lock is aleary acquired or does not support\n");
        else
            perror("Lock Acquired failed\n");
        close(fd);
        exit(0);
    }

    printf("Read lock acquired, press enter to release\n");
    getchar();

    lock.l_type=F_UNLCK;
    if(fcntl(fd,F_SETLK, &lock)==-1)
        perror("Cannot release Read lock\n");
    else
        printf("Read Lock released\n");
    
    close(fd);
}

/*==============================================
Output:
/a.out
Read lock acquired, press enter to release

Read Lock released
================================================*/