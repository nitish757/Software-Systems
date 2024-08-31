/*============================================================== 
Name : 18a.c
Author : Nitish Mahapatre
Description:Write a program to perform Record locking.
                    a. Implement write lock
Date: 31th Aug, 2024
=================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

#define FILE_NAME "records.txt"
#define RECORD_SIZE 20

void lockRecord(int fd, off_t offset, short type) {
    struct flock lock;
    lock.l_type = type;       // Type of lock: F_WRLCK (write)
    lock.l_whence = SEEK_SET; // Lock from the beginning of the file
    lock.l_start = offset;    // Start locking at the given offset
    lock.l_len = RECORD_SIZE; // Length of the lock (size of one record)
    lock.l_pid = getpid();    // Process ID

    if (fcntl(fd, F_SETLKW, &lock) == -1) {  // Use F_SETLKW for blocking locks
        perror("fcntl - lock");
        _exit(1);
    }
}

void unlockRecord(int fd, off_t offset) {
    struct flock lock;
    lock.l_type = F_UNLCK;    // Unlock
    lock.l_whence = SEEK_SET; // Unlock from the beginning of the file
    lock.l_start = offset;    // Unlock from offset
    lock.l_len = RECORD_SIZE; // Length of the unlock

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - unlock");
        _exit(1);
    }
}

void main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <record_number>\n", argv[0]);
        exit(0);
    }

    int fd;
    int record_num = atoi(argv[1]);
    if (record_num < 1 || record_num > 3) {
        fprintf(stderr, "Invalid record number. Must be between 1 and 3.\n");
        exit(0);
    }
    
    off_t offset = (record_num - 1) * RECORD_SIZE;

    fd = open(FILE_NAME, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(0);
    }

    lockRecord(fd, offset, F_WRLCK);
    printf("Write lock acquired for record %d.\n", record_num);

    lseek(fd, offset, SEEK_SET);
    dprintf(fd, "Record %d: Updated Data\n", record_num);

    printf("Press Enter to release the lock...\n");
    getchar();

    unlockRecord(fd, offset);
    printf("Write lock released for record %d.\n", record_num);

    close(fd);

}

/*========================================
Output:
./a.out 2
Write lock acquired for record 2.
Press Enter to release the lock...

Write lock released for record 2.*/