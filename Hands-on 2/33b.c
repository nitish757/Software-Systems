/*
============================================================================
Name : 33b.c
Author : Nitish Mahapatre
Description : Write a program to communicate between two machines using socket.
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

void main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char *message = "Hello from the client!";
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("Socket creation error\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0){
        printf("Invalid address/ Address not supported\n");
        exit(1);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        printf("Connection failed\n");
        exit(1);
    }

    send(sock, message, strlen(message), 0);
    printf("Message sent to server\n");

    read(sock, buffer, 1024);
    printf("Message from server: %s\n", buffer);

    close(sock);
}
/*=====================================================
Output:
Message sent to server
Message from server: Hello from the server!
======================================================*/