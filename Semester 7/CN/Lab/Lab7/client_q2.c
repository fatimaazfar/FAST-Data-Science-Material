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

    // Authentication
    char voter_name[256];
    char voter_cnic[256];
    char buffer[1024];

    printf("Enter your name: ");
    fgets(voter_name, sizeof(voter_name), stdin);
    printf("Enter your CNIC: ");
    fgets(voter_cnic, sizeof(voter_cnic), stdin);

    // Send name and CNIC to the server for authentication
    sprintf(buffer, "%s %s", voter_name, voter_cnic);
    send(client_socket, buffer, sizeof(buffer), 0);

    // Receive authentication result from the server
    recv(client_socket, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    if (strcmp(buffer, "Authenticated") == 0) {
        // Receive and print candidates list
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("%s", buffer);

        for (int i = 0; i < 5; i++) {
            recv(client_socket, buffer, sizeof(buffer), 0);
            printf("%s", buffer);
        }

        // Vote casting
        printf("Enter the poll symbol of the candidate you want to vote for: ");
        fgets(buffer, sizeof(buffer), stdin);
        send(client_socket, buffer, sizeof(buffer), 0);

        // Receive vote recording result
        recv(client_socket, buffer, sizeof(buffer), 0);
        printf("%s", buffer);
    }

    // Close the client socket
    close(client_socket);

    return 0;
}
