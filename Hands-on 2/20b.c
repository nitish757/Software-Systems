/*
============================================================================
Name : 20b.c
Author : Nitish Mahapatre
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 21 Sep, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main(){
    int fd;
    char buf[80];

    fd=open("myfifo1", O_WRONLY);
    printf("Enter the text: ");
    scanf(" %[^\n]", buf);
    write(fd, buf, sizeof(buf));

    close(fd);
}
/*===================================
Output:
Enter the text: Message from program 2
=====================================*/