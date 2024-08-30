/*/*========================================================================
Name : 9.c
Author : Nitish Mahapatre
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 24th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

	int main()
{
	struct stat file_info;
	if (stat("file2", &file_info) == -1)
	{
		perror("program");
		exit(0);
	}
	printf("Inode:%ld\n", (long)file_info.st_ino);
	printf("Numbers of hard links: %ld\n", (long)file_info.st_nlink);
	printf("UID: %u\n", file_info.st_uid);
	printf("GID: %u\n", file_info.st_gid);
	printf("Size: %ld bytes\n", (long)file_info.st_size);
	printf("Block size: %ld\n", (long)file_info.st_blksize);
	printf("#Blocks: %ld\n", (long)file_info.st_blocks);
	printf("Last access time: %s\n", ctime(&file_info.st_atime));
	printf("Last modification time: %s\n", ctime(&file_info.st_mtime));
	printf("Last status change time: %s\n", ctime(&file_info.st_ctime));

	return 0;
}
/*================================================
Output:
./exe9 9
Inode:10096058
Numbers of hard links: 1
UID: 1000
GID: 1000
Size: 19 bytes
Block size: 4096
#Blocks: 8
Last access time: Sat Aug 24 15:35:47 2024

Last modification time: Thu Aug 22 09:08:12 2024

Last status change time: Thu Aug 22 09:08:12 2024
===================================================
*/
