/*============================================================================
Name : 15.c
Author : Nitish Mahapatre
Description : Write a program to display the environmental variable of the user (use environ).
Date: 29th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
extern char **environ;
void main() {
    char **env = environ;
    while (*env) {
        if (strncmp(*env, "USER=", 5) == 0 || strncmp(*env, "HOME=", 5) == 0 ||  strncmp(*env, "SHELL=", 6) == 0)
            printf("%s\n", *env);
        env++; 
    }
}
/*=============================================================
Output:
./a.out
SHELL=/bin/bash
HOME=/home/nitish-mahapatre
USER=nitish-mahapatre*/