#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 5555

int main() {
    int client_socket;
    struct sockaddr_in server_addr;

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        char user_input[1024];
        printf("Enter message (or 'DISCONNECT' to exit): ");
        fgets(user_input, sizeof(user_input), stdin);

        // Send user input to the server
        send(client_socket, user_input, strlen(user_input), 0);

        // Check for "DISCONNECT" command
        if (strcmp(user_input, "DISCONNECT\n") == 0) {
            break;
        }

        // Receive and print the server's response
        recv(client_socket, user_input, sizeof(user_input), 0);
        printf("Received from server: %s", user_input);
    }

    // Close the client socket
    close(client_socket);

    return 0;
}
