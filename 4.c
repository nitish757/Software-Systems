/*========================================================================
Name : 4.c
Author : Nitish Mahapatre
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 20th Aug, 2024.
============================================================================
*/
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
int main(){
	int fd=open("myfile4.txt",O_EXCL, S_IRUSR|S_IWUSR);
	if(fd==-1){
		perror("Error");
		return 1;
	}
	printf("Successfull, fd value=%d",fd);
	return 0;
}
/*============================================
Output:./a.out
Successfull, fd value=3
==============================================*/
