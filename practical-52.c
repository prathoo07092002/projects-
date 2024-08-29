#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads;
    int sum_of_squares = 0;

    // Set the number of threads
    omp_set_num_threads(4);

    // Parallel region
    #pragma omp parallel reduction(+:sum_of_squares)
    {
            // printf("Sum of squares  = %d\n", sum_of_squares);

        int id = omp_get_thread_num();
        // id++;
        int square = id * id;

        // Each thread prints the square of its ID
        printf("Thread %d: Square of ID = %d\n", id, square);

        // Add the square of the thread ID to the sum
        sum_of_squares += square;
    }

    // Print the sum of squares
    printf("Sum of squares of thread IDs = %d\n", sum_of_squares);

    return 0;
}
