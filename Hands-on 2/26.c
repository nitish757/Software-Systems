/*
============================================================================
Name : 26.c
Author : Nitish Mahapatre
Description : Write a program to send messages to the message queue. Check $ipcs -q
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>

struct msg {
    long int mtype;      
    char message[80]; 
};

void main() {
    int msgid;
    key_t key;
    struct msg mg;

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

    printf("Enter the message type: ");
    scanf("%ld", &mg.mtype);

    printf("Enter the message text: ");
    scanf(" %[^\n]", mg.message);

    if (msgsnd(msgid, &mg, strlen(mg.message) + 1, 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }
    printf("Message id=%d\n", msgid);
}
/*======================================
Output:
Enter the message type: 1
Enter the message text: Hello from prog 26            
Message id=3

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41130647 0          nitish-mah 666        0            0           
0x4113064b 1          nitish-mah 666        0            0           
0xffffffff 2          nitish-mah 666        0            0           
0x611302eb 3          nitish-mah 666        80           4  
=======================================*/