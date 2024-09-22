/*
============================================================================
Name : 27a.c
Author : Nitish Mahapatre
Description : Write a program to receive messages from the message queue.
                a. with 0 as a flag
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>
#include <errno.h>

struct message {
    long msg_type;   
    char msg_text[100]; 
};

void main() {
    int key, msgid;

    key = ftok(".", 'a');

    msgid = msgget(key, 0666 | IPC_CREAT);

    struct message msg;

    msgrcv(msgid, &msg, sizeof(msg.msg_text), 0, 0);

    printf("Received message of type %ld: %s\n", msg.msg_type, msg.msg_text);

}
/*===============================
Output:
./a.out
Received message of type 17179869193: Hello from Prog 26
================================*/