/*
============================================================================
Name : 24.c
Author : Nitish Mahapatre
Description : Write a program to create a message queue and print the key and message queue id.
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <sys/types.h>

void main() {
    key_t key;
    int msgid;

    key = ftok("myfifo1", 65);
    if (key == -1) {
        perror("ftok failed");
        exit(1);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    printf("Message Queue Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgid);

}
/*==============================
Output:
Message Queue Key: 1091765835
Message Queue ID: 1
================================*/