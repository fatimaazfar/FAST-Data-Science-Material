#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 1111
#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in serverAddr;

    char buffer[MAX_BUFFER_SIZE];

    // Creating socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error in socket creation");
        exit(EXIT_FAILURE);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));

    // Server information
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    while (1) {
        printf("Enter check-in or check-out request (e.g., 12-4159-CI or 12-4159-CO): ");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Sending message to server
        sendto(sockfd, (const char*)buffer, strlen(buffer), 0, (const struct sockaddr*)&serverAddr, sizeof(serverAddr));

        // Receiving and displaying the server response
        memset(buffer, 0, MAX_BUFFER_SIZE);
        recvfrom(sockfd, (char*)buffer, MAX_BUFFER_SIZE, 0, NULL, NULL);
        printf("Server response: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}
