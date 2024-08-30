/*========================================================================
Name : 6.c
Author : Nitish Mahapatre
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 22th Aug, 2024.
============================================================================
*/
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>

int main(){
	char buffer[32];
	int sie_read =read(0, buffer, 5);
	printf("%d", sie_read);
	//fflush(stdout);
	write(1, buffer, sie_read);
	return 0;
}
/*===========================
Input: hiiii
output: hiiii5
============================*/
