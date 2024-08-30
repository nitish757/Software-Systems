/*============================================================================
Name : 1b.c
Author : Nitish Mahapatre
Description : Create the following types of a files using (i) shell command (ii) system call
				b. hard link (link system call)
Date: 20th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
int main(){
	const char*target="target.txt";
	const char*hardLink="hardLink.txt";
	if(link(target,hardLink)==-1){
		perror("Error");
		return 1;
	}
	printf("Success");
	return 0;
}
/*Output: ./a.out
Success
cat hardLink.txt
this is hard ;link
*/