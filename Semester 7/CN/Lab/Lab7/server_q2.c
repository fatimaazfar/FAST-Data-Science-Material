#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 5555
#define MAX_CLIENTS 5

typedef struct {
    char name[256];
    char cnic[256];
} Voter;

typedef struct {
    char symbol[10];
    char name[256];
} Candidate;

Voter voters[MAX_CLIENTS];
Candidate candidates[MAX_CLIENTS];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
FILE *output_file;

void *handle_client(void *arg);

int authenticate_voter(char *name, char *cnic);
void load_voters();
void load_candidates();
void record_vote(char *voter_name, char *candidate_symbol);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    pthread_t tid;

    output_file = fopen("Vote_Record.txt", "a");
    if (output_file == NULL) {
        perror("Error opening Vote_Record.txt");
        exit(EXIT_FAILURE);
    }

    // Load voters and candidates data
    load_voters();
    load_candidates();

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

    fclose(output_file);
    pthread_mutex_destroy(&mutex);
    close(server_socket);

    return 0;
}

void *handle_client(void *arg) {
    int client_socket = *((int *)arg);
    char buffer[1024];
    char voter_name[256];
    char voter_cnic[256];

    // Receive voter's name and CNIC
    recv(client_socket, buffer, sizeof(buffer), 0);
    sscanf(buffer, "%s %s", voter_name, voter_cnic);

    // Authenticate the voter
    int authentication_result = authenticate_voter(voter_name, voter_cnic);
    if (authentication_result == 0) {
        send(client_socket, "Authenticated", sizeof("Authenticated"), 0);

        // Send candidates list to the voter
        send(client_socket, "Candidates List:\n", sizeof("Candidates List:\n"), 0);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            send(client_socket, candidates[i].symbol, sizeof(candidates[i].symbol), 0);
            send(client_socket, candidates[i].name, sizeof(candidates[i].name), 0);
        }

        // Receive voter's vote
        recv(client_socket, buffer, sizeof(buffer), 0);

        // Record the vote
        pthread_mutex_lock(&mutex);
        record_vote(voter_name, buffer);
        pthread_mutex_unlock(&mutex);

        send(client_socket, "Vote recorded successfully.\n", sizeof("Vote recorded successfully.\n"), 0);
    } else {
        send(client_socket, "Authentication failed.\n", sizeof("Authentication failed.\n"), 0);
    }

    close(client_socket);
    return NULL;
}

int authenticate_voter(char *name, char *cnic) {
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (strcmp(voters[i].name, name) == 0 && strcmp(voters[i].cnic, cnic) == 0) {
            return 0; // Authentication successful
        }
    }
    return -1; // Authentication failed
}

void load_voters() {
    FILE *voters_file = fopen("Voters_List.txt", "r");
    if (voters_file == NULL) {
        perror("Error opening Voters_List.txt");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_CLIENTS; i++) {
        fscanf(voters_file, "%s %s", voters[i].name, voters[i].cnic);
    }

    fclose(voters_file);
}

void load_candidates() {
    FILE *candidates_file = fopen("Candidates_List.txt", "r");
    if (candidates_file == NULL) {
        perror("Error opening Candidates_List.txt");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MAX_CLIENTS; i++) {
        fscanf(candidates_file, "%s %s", candidates[i].symbol, candidates[i].name);
    }

    fclose(candidates_file);
}

void record_vote(char *voter_name, char *candidate_symbol) {
    fprintf(output_file, "Voter: %s\n", voter_name);
    fprintf(output_file, "Vote: %s\n\n", candidate_symbol);
}
