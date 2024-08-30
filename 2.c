/*============================================================================
Name : 2.c
Author : Nitish Mahapatre
Description : Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
			  identify all the process related information in the corresponding proc directory.
Date: 20th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main(){
	int i;
	for(;;){
		printf("Hello");
		sleep(1);
	}
	return 0;
}
