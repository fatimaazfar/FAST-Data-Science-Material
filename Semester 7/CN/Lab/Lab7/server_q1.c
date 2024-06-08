#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5555
#define MAX_CLIENTS 3

void *handle_client(void *arg);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Accept a connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Create a new thread for the client
        pthread_create(&tid, NULL, handle_client, (void *)&client_socket);
        pthread_detach(tid); // Detach the thread to avoid memory leaks
    }

    // Close the server socket (never reached in this example)
    close(server_socket);

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[1024];
    int bytes_received;

    while (1) {
        // Receive data from the client
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Received from client: %s", buffer);

        // Echo back to the client
        send(client_socket, buffer, bytes_received, 0);

        // Check for "DISCONNECT" command
        if (strcmp(buffer, "DISCONNECT\n") == 0) {
            break;
        }
    }

    printf("Client disconnected\n");
    close(client_socket);

    return NULL;
}
