#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

double compute(double x);

int main() {
    double x = 0.5; // Initial value
    double result_seq, result_par;
    double start, end;

    // Sequential computation
    start = omp_get_wtime();
    result_seq = compute(x);
    end = omp_get_wtime();
    printf("Sequential computation time: %f seconds\n", end-start);

    // Parallel computation
    start = omp_get_wtime();
    #pragma omp parallel sections num_threads(4)
    {
        #pragma omp section
        {
            result_par += compute(x);
        }

        #pragma omp section
        {
            result_par += compute(x + 1);
        }

        #pragma omp section
        {
            result_par += compute(x + 2);
        }

        #pragma omp section
        {
            result_par += compute(x + 3);
        }
    }
    end = omp_get_wtime();
    printf("Parallel computation time: %f seconds\n", end-start);

    // Print results
    printf("Sequential result: %f\n", result_seq);
    printf("Parallel result: %f\n", result_par);

    return 0;
}

double compute(double x) {
    double result = 0;
    for (int i = 0; i < 100000000; i++) {
        result += sin(x) * cos(x) * tan(x);
    }
    return result;
}