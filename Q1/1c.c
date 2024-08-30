/*============================================================================
Name : 1c.c
Author : Nitish Mahapatre
Description : Create the following types of a files using (i) shell command (ii) system call
				c. FIFO (mkfifo Library Function or mknod system call)
Date: 20th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<errno.h>
int main(){
	const char* fifo_path="myfifo1";
	
	if(mkfifo(fifo_path,0644)==-1){
		perror("Error"); 
		return 1;
	}
	printf("Sucessfull");
	return 0;
}
/*Output: ls -l myfifo1
prw-r--r-- 1 nitish-mahapatre nitish-mahapatre 0 Aug 27 23:02 myfifo1*/