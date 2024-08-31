/*============================================================== 
Name : 28.c
Author : Nitish Mahapatre
Description: Write a program to get maximum and minimum real time priority.
Date: 31th Aug, 2024
=================================================================
*/
#include <stdio.h>
#include <sched.h>

void main() {
    int max_priority_fifo, min_priority_fifo;
    int max_priority_rr, min_priority_rr;

    max_priority_fifo = sched_get_priority_max(SCHED_FIFO);
    min_priority_fifo = sched_get_priority_min(SCHED_FIFO);

    max_priority_rr = sched_get_priority_max(SCHED_RR);
    min_priority_rr = sched_get_priority_min(SCHED_RR);

    printf("SCHED_FIFO: Max Priority = %d, Min Priority = %d\n", max_priority_fifo, min_priority_fifo);
    printf("SCHED_RR: Max Priority = %d, Min Priority = %d\n", max_priority_rr, min_priority_rr);

}
/*===========================================================
Output:
./a.out
SCHED_FIFO: Max Priority = 99, Min Priority = 1
SCHED_RR: Max Priority = 99, Min Priority = 1*/