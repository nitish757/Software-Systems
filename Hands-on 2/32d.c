/*
============================================================================
Name : 32d.c
Author : Nitish Mahapatre
Description : Write a program to implement semaphore to protect any critical section.
                    d. remove the created semaphore
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>

void main(){
    sem_unlink("/ticket_semaphore");

    sem_unlink("/shared_memory_semaphore");

    sem_unlink("/counting_semaphore");

    printf("Semaphores removed successfully.\n");
}
/*=====================================================
Output:
Semaphores removed successfully
========================================================*/