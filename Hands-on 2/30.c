/*
============================================================================
Name : 30.c
Author : Nitish Mahapatre
Description : Write a program to create a shared memory.
                a. write some data to the shared memory
                b. attach with O_RDONLY and check whether you are able to overwrite.
                c. detach the shared memory
                d. remove the shared memory
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>

void main() {
    key_t key;
    int shm_id;
    char *shm_ptr;

    key = ftok(".", 'a');
    if (key == -1) {
        perror("ftok failed");
        exit(1);
    }

    shm_id = shmget(key, 1024, IPC_CREAT | 0666);
    if (shm_id == -1) {
        perror("shmget failed");
        exit(1);
    }

    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (char *) -1) {
        perror("shmat failed");
        exit(1);
    }

    strcpy(shm_ptr, "Hello, this is shared memory!");
    printf("Written to shared memory: %s\n", shm_ptr);

    if (shmdt(shm_ptr) == -1) {
        perror("shmdt failed");
        exit(1);
    }

    shm_ptr = shmat(shm_id, NULL, SHM_RDONLY);
    if (shm_ptr == (char *) -1) {
        perror("shmat (read-only) failed");
        exit(1);
    }

    printf("Attempting to overwrite shared memory...\n");

    //strcpy(shm_ptr, "Trying to overwrite!");

    printf("Current content of shared memory: %s\n", shm_ptr);

    if (shmdt(shm_ptr) == -1) {
        perror("shmdt failed");
        exit(1);
    }

    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("shmctl failed");
        exit(1);
    }

    printf("Shared memory removed successfully.\n");
}
/*================================================================
Output:
Written to shared memory: Hello, this is shared memory!
Attempting to overwrite shared memory...
Current content of shared memory: Hello, this is shared memory!
Shared memory removed successfully.
===================================================================*/