/*
============================================================================
Name : 22.c
Author : Nitish Mahapatre
Description : Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
Date: 21 Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>

void main(){
    int fd, retval;
    char buf[80];
    fd_set rfds;
    struct timeval tv;

    fd= open("myfifo", O_RDONLY);
    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);
    tv.tv_sec=5;
    tv.tv_usec=0;
    retval=select(fd+1, &rfds, NULL, NULL, &tv);

    if(retval)
        printf("Data is available now....\n");
    else{
        printf("No Data is available within 5 second....\n");
        exit(0);
    }
    read(fd, buf, sizeof(buf));
    printf("The text from FIFO: %s\n", buf);
}
/*============================================
Output:
Data is available now....
The text from FIFO: For Progarm 22
==============================================*/