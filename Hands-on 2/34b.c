/*
============================================================================
Name : 34b.c
Author : Nitish Mahapatre
Description : Write a program to create a concurrent server.
                b. use pthread_create
Date: 21 Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int client_count = 1;
pthread_mutex_t count_mutex; 

void* handle_client(void* client_socket) 
{
    int sock = *((int*)client_socket);
    char buffer[1024];
    int n;

    pthread_mutex_lock(&count_mutex);
    int client_id = client_count++;
    pthread_mutex_unlock(&count_mutex);

    printf("Client %d connected\n", client_id);

    while ((n = read(sock, buffer, sizeof(buffer))) > 0) 
    {
        buffer[n] = '\0';
        printf("Client %d: %s\n", client_id, buffer);
        write(sock, buffer, n);
    }

    close(sock);
    printf("Client %d disconnected\n", client_id);
    return NULL;
}

void main() 
{
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    pthread_t tid;

    pthread_mutex_init(&count_mutex, NULL);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
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

        if (pthread_create(&tid, NULL, handle_client, (void*)&client_socket) != 0) {
            perror("Failed to create thread");
            exit(1);
        }

        pthread_detach(tid); 
    }
    pthread_mutex_destroy(&count_mutex);
    close(server_socket);
}
/*
============================================================================
Output:
    Server is listening on port 8080...
Connected to Client 1
Connected to Client 2
Client 1: Hello C1

Client 2: Hi C2

Client 2: Bye C2

Client 1: Bye C1

Client disconnected 1
Client disconnected 2
============================================================================
*/