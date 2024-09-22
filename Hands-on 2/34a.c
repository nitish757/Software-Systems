/*
============================================================================
Name : 34a.c
Author : Nitish Mahapatre
Description : Write a program to create a concurrent server.
                a. use fork
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

void handle_client(int client_socket, int client_counter) 
{
    char buffer[1024];
    int n;

    while ((n = read(client_socket, buffer, sizeof(buffer))) > 0) 
    {
        buffer[n] = '\0';
        printf("Client %d: %s\n", client_counter, buffer);
        write(client_socket, buffer, n);
    }

    close(client_socket);
    printf("Client disconnected %d\n", client_counter);
}

void main() 
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pid_t child_pid;
    int client_counter = 0;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0){
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        perror("Bind failed");
        exit(1);
    }

    if (listen(server_socket, 10) < 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("Server is listening on port %d...\n", 8080);

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
        if (client_socket < 0) {
            perror("Accept failed");
            exit(1);
        }
        client_counter++;
        printf("Connected to Client %d\n", client_counter);

        if ((child_pid = fork()) == 0) {
            close(server_socket);
            handle_client(client_socket, client_counter);
            exit(0);
        }

        close(client_socket);
    }

    close(server_socket);
}
/*
============================================================================
Output:
    Server is listening on port 8080...
Connected to Client 1
Client 1: 

Client 1: HI

Connected to Client 2
Client 2: Hi client 1

Client 1: hello client 2

Client 2: how are you?

Client 1: I am Fine and you?

Client 2: bye

Client 1: bye

Client disconnected 2
Client disconnected 1
============================================================================
*/