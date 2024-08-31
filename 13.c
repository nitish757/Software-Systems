/*============================================================== 
Name : 13.c
Author : Nitish Mahapatre
Description:Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
            verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 31th Aug, 2024
=================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>

void main(){
    fd_set readfds;
    struct timeval timeout;
    int result;

    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    printf("Waiting for input on STDIN for 10 seconds...\n");

    result = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
        exit(0);
    } else if (result == 0) {
        printf("No data was entered within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            char buffer[256];
            read(STDIN_FILENO, buffer, sizeof(buffer));
            printf("Data is available: %s\n", buffer);
        }
    }

}
/*==================================================
Output:
/a.out
Waiting for input on STDIN for 10 seconds...
my name is 13 
Data is available: my name is 13*/