/*
============================================================================
Name : 3.c
Author : Nitish Mahapatre
Description : Write a program to set (any one) system resource limit. Use setrlimit system call.
Date: 12th Sep, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<sys/resource.h>

void main(){
    struct rlimit limit;

    if(getrlimit(RLIMIT_NOFILE, &limit)==0)
        printf("Old Max No. of open files\n\tSoft limit:%ld  Hard Limit:%ld\n",(long)limit.rlim_cur,(long)limit.rlim_max);
    else{
        perror("Error while getting old limits\n");
        exit(1);
    }

    limit.rlim_cur=1048576;
    limit.rlim_max=1048576;

    if(setrlimit(RLIMIT_NOFILE, &limit)==0){
        printf("New Limits has been set\n");
    }
    else{
        perror("Error while setting new limits\n");
        exit(1);
    }


    if(getrlimit(RLIMIT_NOFILE, &limit)==0)
        printf("New Max No. of open files\n\tSoft limit:%ld  Hard Limit:%ld\n",(long)limit.rlim_cur,(long)limit.rlim_max);
    else{
        perror("Error while getting old limits\n");
        exit(1);
    }    
}
/*==============================================================================
Output:
Old Max No. of open files
        Soft limit:1048576  Hard Limit:1048576
New Limits has been set
New Max No. of open files
        Soft limit:524288  Hard Limit:524288*/