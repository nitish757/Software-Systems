/*============================================================================
Name : 1a.c
Author : Nitish Mahapatre
Description : Create the following types of a files using (i) shell command (ii) system call
				a. soft link (symlink system call)
Date: 20th Aug, 2024.
============================================================================
*/


#include<unistd.h>
#include<stdio.h>
int main(){
	const char *targetPath="hello.txt";
	const char *linkPath="Symlink.txt";

	if(symlink(targetPath,linkPath)==-1){
		perror("Error\n");
		return 1;
	}
	printf("Success\n");
	return 0;

}
/*Output:
./a.out
Success
cat Symlink.txt
this is for symlink
*/

