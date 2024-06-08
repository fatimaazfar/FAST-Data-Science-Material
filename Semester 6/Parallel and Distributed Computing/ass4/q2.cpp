#include <iostream>
#include <vector>
#include <algorithm>
#include <mpi.h>
#include <omp.h>

using namespace std;

void mergeSort(vector<int>& arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    #pragma omp parallel sections
    {
        #pragma omp section
        mergeSort(arr, start, mid);
        #pragma omp section
        mergeSort(arr, mid + 1, end);
    }
    inplace_merge(arr.begin() + start, arr.begin() + mid + 1, arr.begin() + end + 1, greater<int>());
}

int main(int argc, char* argv[]) {
    int num_procs, rank;
    int m = 4, n = 5;
    vector<int> matrix(m * n);
    vector<int> local_row(n);

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Initialize the matrix on the root process
    if (rank == 0) {
        for (int i = 0; i < m * n; i++) {
            matrix[i] = rand() % 100;
        }
        cout << "Original matrix: " << endl;
        for (int i = 0; i < m * n; i++) {
            cout << matrix[i] << " ";
            if ((i + 1) % n == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }

    // Scatter the matrix rows to each process
    MPI_Scatter(&matrix[0], n, MPI_INT, &local_row[0], n, MPI_INT, 0, MPI_COMM_WORLD);

    // Sort the local row using merge sort
    mergeSort(local_row, 0, n - 1);

    // Compute the sum of the local row
    int local_sum = 0;
    #pragma omp parallel for reduction(+:local_sum)
    for (int i = 0; i < n; i++) {
        local_sum += local_row[i];
    }

    // Gather the sorted rows on the root process
    vector<int> sorted_rows(m * n);
    MPI_Gather(&local_row[0], n, MPI_INT, &sorted_rows[0], n, MPI_INT, 0, MPI_COMM_WORLD);

    // Perform all-to-one reduction to compute the sum of the matrix
    int global_sum = 0;
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Display the sorted matrix and global sum
    if (rank == 0) {
        cout << "Sorted matrix: " << endl;
        for (int i = 0; i < m * n; i++) {
            cout << sorted_rows[i] << " ";
            if ((i + 1) % n == 0) {
                cout << endl;
            }
        }
        cout << "Global sum: " << global_sum << endl;
    }

    MPI_Finalize();
    return 0;
}