#include <iostream>
#include <vector>
#include <mpi.h>

using namespace std;

int main(int argc, char* argv[]) {
    int num_procs, rank;
    const int n = 1000;
    vector<int> arr(n);

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Calculate the size of the chunk that each process will work on
    int chunk_size = n / num_procs;

    // Initialize the array on all processes
    for (int i = rank * chunk_size; i < (rank + 1) * chunk_size; i++) {
        arr[i] = i;
    }

    // Find the local maximum
    int local_max = arr[rank * chunk_size];
    for (int i = rank * chunk_size + 1; i < (rank + 1) * chunk_size; i++) {
        if (arr[i] > local_max) {
            local_max = arr[i];
        }
    }

    // Send the local maximum to the root process
    if (rank != 0) {
        MPI_Send(&local_max, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } else {
        vector<int> max_vals(num_procs);
        max_vals[0] = local_max;
        for (int i = 1; i < num_procs; i++) {
            MPI_Recv(&max_vals[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        // Find the global maximum on the root process
        int global_max = max_vals[0];
        for (int i = 1; i < num_procs; i++) {
            if (max_vals[i] > global_max) {
                global_max = max_vals[i];
            }
        }
        cout << "Maximum value: " << global_max << endl;
    }

    MPI_Finalize();
    return 0;
}