/*============================================================== 
Name : 18b.c
Author : Nitish Mahapatre
Description:Write a program to perform Record locking.
                    b. Implement read lock
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
    lock.l_type = type;       // Type of lock: F_RDLCK (read)
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

    lockRecord(fd, offset, F_RDLCK);
    printf("Read lock acquired for record %d.\n", record_num);

    lseek(fd, offset, SEEK_SET);
    char buffer[RECORD_SIZE + 1];
    if (read(fd, buffer, RECORD_SIZE) < 0) {
        perror("read");
        unlockRecord(fd, offset);
        close(fd);
        exit(0);
    }
    buffer[RECORD_SIZE] = '\0';
    printf("Record %d data: %s", record_num, buffer);

    printf("Press Enter to release the lock...\n");
    getchar();

    unlockRecord(fd, offset);
    printf("Read lock released for record %d.\n", record_num);

    close(fd);

}

/*=====================================
Output:
./a.out 2
Read lock acquired for record 2.
Record 2 data: Record 2: Updated DaPress Enter to release the lock...

Read lock released for record 2.*/