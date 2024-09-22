/*
============================================================================
Name : 28.c
Author : Nitish Mahapatre
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

void main() {
    key_t key;
    int msgid;
    struct msqid_ds msg_info;

    key = ftok(".", 'a');
    if (key == -1) {
        perror("ftok failed");
        exit(1);
    }

    msgid = msgget(key, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget failed");
        exit(1);
    }

    if (msgctl(msgid, IPC_STAT, &msg_info) == -1) {
        perror("msgctl IPC_STAT failed");
        exit(1);
    }

    printf("Current permissions: %o\n", msg_info.msg_perm.mode);

    msg_info.msg_perm.mode = 0644;

    if (msgctl(msgid, IPC_SET, &msg_info) == -1) {
        perror("msgctl IPC_SET failed");
        exit(1);
    }

    if (msgctl(msgid, IPC_STAT, &msg_info) == -1) {
        perror("msgctl IPC_STAT failed");
        exit(1);
    }

    printf("Updated permissions: %o\n", msg_info.msg_perm.mode);
}
/*===================================
Output:
Current permissions: 666
Updated permissions: 644
=====================================*/