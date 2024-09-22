/*
============================================================================
Name : 29.c
Author : Nitish Mahapatre
Description : Write a program to remove the message queue.
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>

void main() 
{
    key_t key = ftok("myfifo", 65); 
    if (key == -1){
        perror("ftok");
        exit(1);
    }

    int msgid = msgget(key, 0666);
    if (msgid == -1){
        perror("msgget");
        exit(1);
    }

    printf("Message queue found with ID: %d\n", msgid);

    if (msgctl(msgid, IPC_RMID, NULL) == -1){
        perror("msgctl IPC_RMID");
        exit(1);
    }

    printf("Message queue removed successfully.\n");
}
/*=============================================
Output:
Message queue found with ID: 0
Message queue removed successfully.
===============================================*/