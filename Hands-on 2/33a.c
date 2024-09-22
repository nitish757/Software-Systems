/*
============================================================================
Name : 33a.c
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
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(){
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *message = "Hello from the server!";

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0){
        perror("socket failed");
        exit(1);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsockopt failed");
        exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0){
        perror("bind failed");
        close(server_fd);
        exit(1);
    }

    if (listen(server_fd, 3) < 0){
        perror("listen failed");
        close(server_fd);
        exit(1);
    }

    printf("Server is listening on port %d\n", 8080);

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0){
        perror("accept failed");
        close(server_fd);
        exit(1);
    }

    read(new_socket, buffer, 1024);
    printf("Message from client: %s\n", buffer);

    send(new_socket, message, strlen(message), 0);
    printf("Hello message sent from server\n");

    close(new_socket);
    close(server_fd);
}
/*=====================================================
Output:
Server is listening on port 8080
Message from client: Hello from the client!
Hello message sent from server
=======================================================*/