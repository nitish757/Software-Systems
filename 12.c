/*============================================================================
Name : 12.c
Author : Nitish Mahapatre
Description : Write a program to create five new files with infinite loop. Execute the program in the background
			  and check the file descriptor table at /proc/pid/fd.
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include<stdlib.h>

void main(){
    int fd, flag;
    fd=open("file12.txt", O_RDWR|O_CREAT|O_APPEND,0664);

    if(fd==-1){
        perror("error fd\n");
        exit(0);
    }

    flag=fcntl(fd,F_GETFL);
    if(flag==-1){
        perror("flag error\n");
        exit(0);
    }

    switch(flag&O_ACCMODE){
        case O_RDONLY: 
            printf("Opeing mode of the file is Read Only\n");
            break;
        case O_RDWR: 
            printf("Opeing mode of the file is Read Write\n");
            break;
        case O_WRONLY:
            printf("Opeing mode of the file is Write Only\n");
            break;
        default:
            printf("Unknown file access mode\n");
            break; 
    }
    if (flag&O_APPEND) {
        printf("Opeing mode of the file is append mode\n");
    }
    if (flag&O_CREAT) {
        printf("File is opened with O_CREAT flag\n");
    }
    if (flag&O_TRUNC) {
        printf("File is opened with O_TRUNC flag\n");
    }
}
/*Output:./a.out
Opeing mode of the file is Read Write
Opeing mode of the file is append mode*/