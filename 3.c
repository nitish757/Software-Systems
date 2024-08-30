/*==========================================================================
Name : 3.c
Author : Nitish Mahapatre
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 20th Aug, 2024.
============================================================================
*/
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<errno.h>
#include<stdio.h>
int main(){
	int fd =creat("myfile3", O_RDONLY);
	if(fd==-1){
		perror("error");
		return 1;
	}
	printf("successfull, File Descriptor value=%d",fd);
	return 0;
}
/*======================================
Output:
./a.out
successfull, File Descriptor value=3
========================================*/