#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define PORT 1111
#define MAX_BUFFER_SIZE 1024
#define DATABASE_FILE "students.csv"

struct Student {
    char year[3];
    char roll[5];
    time_t checkInTime;
    time_t checkOutTime;
};

struct Student database[100];
int numberOfStudents = 0;

void loadDatabaseFromFile() {
    FILE *file = fopen(DATABASE_FILE, "r");
    if (file == NULL) {
        file = fopen(DATABASE_FILE, "w");
        if (file == NULL) {
            perror("Error creating database file");
            exit(EXIT_FAILURE);
        }
        fclose(file);
        return;
    }

    while (fscanf(file, "%2s-%4s,%ld,%ld\n", database[numberOfStudents].year, 
           database[numberOfStudents].roll, &database[numberOfStudents].checkInTime,
           &database[numberOfStudents].checkOutTime) == 4) {
        numberOfStudents++;
    }

    fclose(file);
}

void updateDatabaseToFile() {
    FILE *file = fopen(DATABASE_FILE, "w");
    if (file == NULL) {
        perror("Error opening database file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < numberOfStudents; ++i) {
        fprintf(file, "%s-%s,%ld,%ld\n", database[i].year, database[i].roll,
                database[i].checkInTime, database[i].checkOutTime);
    }

    fclose(file);
}

void processPacket(int sockfd, char* buffer, struct sockaddr_in clientAddr) {
    char responseMessage[MAX_BUFFER_SIZE];

    char year[3], roll[5], action[3];
    sscanf(buffer, "%2s-%4s-%2s", year, roll, action);

    time_t currentTime = time(NULL);
    int found = 0;

    if (strcmp(action, "CI") == 0) {  // Check-in
        for (int i = 0; i < numberOfStudents; ++i) {
            if (strcmp(database[i].year, year) == 0 && strcmp(database[i].roll, roll) == 0) {
                found = 1;
                strcpy(responseMessage, "You are already here.");
                break;
            }
        }

        if (!found) {
            strcpy(database[numberOfStudents].year, year);
            strcpy(database[numberOfStudents].roll, roll);
            database[numberOfStudents].checkInTime = currentTime;
            database[numberOfStudents].checkOutTime = 0;
            numberOfStudents++;
            sprintf(responseMessage, "Welcome Student %s-%s", year, roll);
        }
    } else if (strcmp(action, "CO") == 0) {  // Check-out
        int foundIndex = -1;
        for (int i = 0; i < numberOfStudents; ++i) {
            if (strcmp(database[i].year, year) == 0 && strcmp(database[i].roll, roll) == 0) {
                foundIndex = i;
                found = 1;
                if (database[i].checkOutTime == 0) {
                    database[i].checkOutTime = currentTime;
                    sprintf(responseMessage, "Good Bye Student %s-%s! Have a nice day.", year, roll);
                } else {
                    strcpy(responseMessage, "You are already checked out.");
                }
                break;
            }
        }

        if (foundIndex != -1) {
            // Remove the checked-out student by shifting the remaining students
            for (int i = foundIndex; i < numberOfStudents - 1; i++) {
                strcpy(database[i].year, database[i + 1].year);
                strcpy(database[i].roll, database[i + 1].roll);
                database[i].checkInTime = database[i + 1].checkInTime;
                database[i].checkOutTime = database[i + 1].checkOutTime;
            }
            numberOfStudents--;
        }

        if (!found) {
            sprintf(responseMessage, "You didn't check in today. Contact System Administrator.");
        }
    } else {
        strcpy(responseMessage, "Invalid action.");
    }

    if (strcmp(responseMessage, "You are already here.") != 0 && strcmp(responseMessage, "You are already checked out.") != 0) {
        sendto(sockfd, responseMessage, strlen(responseMessage), 0, (const struct sockaddr*)&clientAddr, sizeof(clientAddr));
    }

    // Print members present in the database
    if (strcmp(action, "CO") != 0) {
        printf("Members present in the database:\n");
        for (int i = 0; i < numberOfStudents; ++i) {
            printf("Student %s-%s\n", database[i].year, database[i].roll);
        }
    }

    // Update the database file
    updateDatabaseToFile();
}


int main() {
    int sockfd;
    struct sockaddr_in serverAddr, clientAddr;
    char buffer[MAX_BUFFER_SIZE];

    // Creating socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error in socket creation");
        exit(EXIT_FAILURE);
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));

    // Server information
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Binding socket
    if (bind(sockfd, (const struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error in binding");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Load initial database from file
    loadDatabaseFromFile();

    while (1) {
        socklen_t len = sizeof(clientAddr);

        // Listening for messages from client
        int recvBytes = recvfrom(sockfd, (char*)buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&clientAddr, &len);
        buffer[recvBytes] = '\0';

        // Processing the received packet
        processPacket(sockfd, buffer, clientAddr);
    }

    close(sockfd);
    return 0;
}
