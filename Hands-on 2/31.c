#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <errno.h>

void operate_semaphore(int semid, int op) {
    struct sembuf sem_op;
    sem_op.sem_num = 0; 
    sem_op.sem_op = op;
    sem_op.sem_flg = 0;

    if (semop(semid, &sem_op, 1) == -1) {
        perror("semop failed");
        exit(1);
    }
}

void main() {
    key_t key = ftok(".", 'a'); 
    int semid = semget(key, 1, IPC_CREAT | 0666); 

    if (semid == -1) {
        perror("semget failed");
        exit(1);
    }

    if (semctl(semid, 0, SETVAL, 1) == -1) {
        perror("semctl failed");
        exit(1);
    }
    printf("Binary semaphore created and initialized to 1.\n");

    if (semctl(semid, 0, IPC_RMID) == -1) {
        perror("semctl remove failed");
        exit(1);
    }

}
