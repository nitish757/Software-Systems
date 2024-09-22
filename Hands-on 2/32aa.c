/*
============================================================================
Name : 32aa.c
Author : Nitish Mahapatre
Description : Write a program to implement semaphore to protect any critical section.
                    a. rewrite the ticket number creation program using semaphore
Date: 21 Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

void main() 
{
    sem_t *semaphore = sem_open("/ticket_semaphore", O_CREAT, 0644, 1); 
    if (semaphore == SEM_FAILED){
        perror("sem_open");
        exit(1);
    }

    int ticket_number = 1; 

    sem_wait(semaphore); 
    FILE *file = fopen("ticket.txt", "w");
    if (file == NULL){
        perror("fopen");
        sem_post(semaphore); 
        exit(1);
    }
    fprintf(file, "%d", ticket_number);
    fclose(file);
    printf("Ticket number %d created.\n", ticket_number);
    sem_post(semaphore); 

    sem_close(semaphore); 
}
/*===================================
Output:
Ticket number 1 created.
=====================================*/