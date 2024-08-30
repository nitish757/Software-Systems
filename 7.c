/*========================================================================
Name : 7.c
Author : Nitish Mahapatre
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 22th Aug, 2024.
============================================================================
*/
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>

int main(int argc, char*argv[]){
	int file1=open(argv[1],O_RDONLY);
	if(argc<3){
		perror("Argument number should be equal to 3\n");
		exit(0);
	}
	if(file1==-1){
		perror("error file 1");
		exit(0);
	}

	int file2=open(argv[2], O_WRONLY | O_EXCL| O_CREAT, 0644);
	if(file2==-1){
		perror("error file 2");
		exit(0);
	}

	char buffer[1024];
	int sie_read;
	while((sie_read=read(file1, buffer, sizeof(buffer)))>0){
		write(file2, buffer, sie_read);
	}

	close(file1);
	close(file2);
	return 0;
}
