/*========================================================================
Name : 10.c
Author : Nitish Mahapatre
Description :Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
			bytes (use lseek) and write again 10 bytes.
				a. check the return value of lseek
				b. open the file with od and check the empty spaces in between the data.
Date: 27th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(){
	int fd;
	off_t os;
	const char* file="file10.txt";
	fd=open(file, O_RDWR|O_CREAT, 0644);
	if(fd==-1){
		perror("file cannot be created\n");
		exit(0);
	}
	const char *first="asdfghjklo";
	if(write(fd,first,strlen(first))==-1){
		perror("first data cannot be written\n");
		close(fd);
		exit(0);
	}
	printf("First 10B written\n");
	os=lseek(fd,10,SEEK_CUR);
	if(os==-1){
		perror("offset failed\n");
		exit(0);
	}
	const char* second="qwertyuiop";
	if(write(fd,second, strlen(second))==-1){
		perror("second data cannot be written\n");
		close(fd);
		exit(0);
	}
	printf("Seond 10B written\n");
	close(fd);
	return 0;
}
/*===============================================
Output:
First 10B written
Seond 10B written


od -c file10.txt
0000000   a   s   d   f   g   h   j   k   l   o  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   q   w   e   r   t   y   u   i   o   p
0000036
=================================================*/

