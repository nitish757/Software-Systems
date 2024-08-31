
/*============================================================================
Name : 14.c
Author : Nitish Mahapatre
Description : Write a program to find the type of a file.
                    a. Input should be taken from command line.
                    b. program should be able to identify any type of a file.
Date: 29th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char* argv[]){

    if(argc!=2){
        perror("input error\n");
        exit(0);
    }

    struct stat filestat;
    if(lstat(argv[1],&filestat)==-1){
        perror("revreive error\n");
        exit(0);
    }

    if(S_ISREG(filestat.st_mode)){
        printf("Regular file\n");
    }else if(S_ISDIR(filestat.st_mode)){
        printf("Directory\n");
    }else if(S_ISLNK(filestat.st_mode)){
        printf("Symbolic link\n");
    }else if(S_ISCHR(filestat.st_mode)){
        printf("Character Device\n");
    }else if(S_ISBLK(filestat.st_mode)){
        printf("Block DEvice\n");
    }else if(S_ISSOCK(filestat.st_mode)){
        printf("Socket\n");
    }else if(S_ISFIFO(filestat.st_mode)){
        printf("FIFO\n");
    }else{
        printf("unkown file type\n");
    }

    return 0;
}
/*============================================
Output:
./a.out Symlink.txt
Symbolic link
./a.out file10.txt
Regular file
==============================================*/