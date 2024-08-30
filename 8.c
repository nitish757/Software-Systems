/*========================================================================
Name : 8.c
Author : Nitish Mahapatre
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
			  Close the file when end of file is reached.
Date: 22th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
const char E0L='\n';

int main(){
	FILE* fd = fopen("file8.txt", "r");
	if(fd==NULL){
	 perror("program");
	exit(0);
	}
	int c=fgetc(fd);
	char buffer[1024];
	int k=0;
	while(c!=EOF){
		while(c!=EOF){
			buffer[k]=c;
			k++;
			c=fgetc(fd);
		}
		buffer[k++]='\n';
		write(1,buffer,k);
		buffer[0]='\0';
		c=fgetc(fd);
		k=0;
	}
	fclose(fd);
	return 0;
}
/*===============================
Output:
./a.out
line 1
line 2
line 3
line4*/