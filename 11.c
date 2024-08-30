/*============================================================== 
Name : 11.c
Author : Nitish Mahapatre
Description:Write a program to open a file, duplicate the file descriptor and append the file with both the
            descriptors and check whether the file is updated properly or not.
                    a. use dup
                    b. use dup2
                    c. use fcntl
Date: 27th Aug, 2024
=================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
void main(){
    int fd,fd1,fd2,fd3;
    fd=open("file11.txt", O_WRONLY|O_CREAT|O_APPEND, 0644);
    if(fd==-1){
        perror("File cannot be opened\n");
        exit(0);
    }
    fd1=dup(fd);
    const char* data1="Data from dup\n";
    if(write(fd1,data1,strlen(data1))==-1){
        perror("dup\n");
        exit(0);
    }
    fd2=dup2(fd,fd1+1);
    const char* data2="Data from dup2\n";
    if(write(fd2,data2,strlen(data2))==-1){
        perror("dup2\n");
        exit(0);
    }
    fd3=fcntl(fd, F_DUPFD, fd2+1);
    const char* data3="Data from fcntl\n";
    if(write(fd3,data3,strlen(data3))==-1){
        perror("fcntl\n");
        exit(0);
    }
    close(fd);
    close(fd1);
    close(fd2);
    close(fd3);

    printf("File updated successfully\n");

    fd=open("file11.txt", O_RDONLY);
    char buffer[256];
    ssize_t br = read(fd, buffer, sizeof(buffer) - 1);
    if (br < 0) {
        perror("read");
        close(fd);
        exit(0);
    }
    printf("%s\n",buffer);

}
/*========================================================
Output:File updated successfully
Data from dup
Data from dup2
Data from fcntl*/