/*============================================================================
Name : 5.c
Author : Nitish Mahapatre
Description : Write a program to create five new files with infinite loop. Execute the program in the background
			  and check the file descriptor table at /proc/pid/fd.
Date: 24th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

int main(){
	int c=0;
	pid_t pid=getpid();
	printf("proces id=%d\n",pid);
	fflush(stdout);
	while(1){
		while(c<5){
			char filename[20];
			snprintf(filename, sizeof(filename), "file_%d.txt",c);
			FILE* file=fopen(filename, "w");
			
			if(file==NULL){
				perror("file not created\n");
				exit(0);
			}
			printf("%s created\n",filename);
			fflush(stdout);
			c++;
			sleep(20);
			fclose(file);
	}
	}
	return 0;
}
/*Output:
proces id=4128
file_0.txt created
file_1.txt created
file_2.txt created
file_3.txt created
file_4.txt created*/
