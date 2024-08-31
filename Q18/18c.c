/*============================================================== 
Name : 18c.c
Author : Nitish Mahapatre
Description:Create three records in a file. Whenever you access a particular record, first lock it then modify/access
            to avoid race condition.
Date: 31th Aug, 2024
=================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FILE_NAME "records.txt"

void createFileWithRecords() {
    int fd;
    const char *records[] = {
        "Record 1: Initial Data\n",
        "Record 2: Initial Data\n",
        "Record 3: Initial Data\n"
    };

    fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }

    for (int i = 0; i < 3; ++i) {
        if (write(fd, records[i], 20) == -1) {
            perror("write");
            close(fd);
            return;
        }
    }

    printf("File created and records written.\n");
    close(fd);
}

void main() {
    createFileWithRecords();
}

/*===================================
Output:
./a.out
File created and records written.*/