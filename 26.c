/*============================================================== 
Name : 26.c
Author : Nitish Mahapatre
Description:Write a program to execute an executable program.
                a. use some executable program
                b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 31th Aug, 2024
=================================================================
*/
#include <unistd.h>

void main()
{
    char *executable_path = "./exe9";
    char *arg = "9.c";

    execl(executable_path, executable_path, arg, NULL);
}

/*============================================
Output:
./a.out
Inode:10096058
Numbers of hard links: 1
UID: 1000
GID: 1000
Size: 19 bytes
Block size: 4096
#Blocks: 8
Last access time: Sat Aug 24 15:35:47 2024

Last modification time: Thu Aug 22 09:08:12 2024

Last status change time: Thu Aug 22 09:08:12 2024*/