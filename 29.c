/*============================================================== 
Name : 29.c
Author : Nitish Mahapatre
Description: Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
             SCHED_RR).
Date: 31th Aug, 2024
=================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void main() {
    pid_t pid = getpid();
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        exit(0);
    }

    printf("Current Scheduling Policy: ");
    switch (policy) {
        case SCHED_OTHER: printf("SCHED_OTHER\n"); break;
        case SCHED_FIFO: printf("SCHED_FIFO\n"); break;
        case SCHED_RR: printf("SCHED_RR\n"); break;
        default: printf("Unknown\n");
    }

    param.sched_priority = sched_get_priority_max(SCHED_FIFO);
    if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler to SCHED_FIFO failed");
        exit(0);
    }

    printf("Scheduling policy changed to SCHED_FIFO with priority %d\n", param.sched_priority);

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        exit(0);
    }

    printf("New Scheduling Policy: ");
    switch (policy) {
        case SCHED_OTHER: printf("SCHED_OTHER\n"); break;
        case SCHED_FIFO: printf("SCHED_FIFO\n"); break;
        case SCHED_RR: printf("SCHED_RR\n"); break;
        default: printf("Unknown\n");
    }

    param.sched_priority = sched_get_priority_max(SCHED_RR); 
    if (sched_setscheduler(pid, SCHED_RR, &param) == -1) {
        perror("sched_setscheduler to SCHED_RR failed");
        exit(0);
    }

    printf("Scheduling policy changed to SCHED_RR with priority %d\n", param.sched_priority);

    policy = sched_getscheduler(pid);
    if (policy == -1) {
        perror("sched_getscheduler failed");
        exit(0);
    }

    printf("Final Scheduling Policy: ");
    switch (policy) {
        case SCHED_OTHER: printf("SCHED_OTHER\n"); break;
        case SCHED_FIFO: printf("SCHED_FIFO\n"); break;
        case SCHED_RR: printf("SCHED_RR\n"); break;
        default: printf("Unknown\n");
    }
}
/*============================================================
Output:
sudo ./exe29
Current Scheduling Policy: SCHED_OTHER
Scheduling policy changed to SCHED_FIFO with priority 99
New Scheduling Policy: SCHED_FIFO
Scheduling policy changed to SCHED_RR with priority 99
Final Scheduling Policy: SCHED_RR*/