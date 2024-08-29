#include <stdio.h>
#include <omp.h>

int main() {
    int num_threads;
    int Arryabhatta = 10;

    // Set the number of threads
    omp_set_num_threads(4);

    // Parallel region
    #pragma omp parallel  private(Aryabhatta)
    {
            // printf("Sum of squares  = %d\n", sum_of_squares);

        int id = omp_get_thread_num();
    

        // Each thread prints the square of its ID
        printf("Thread %d:\n", id);

        // Add the square of the thread ID to the sum
           printf("multiplication of thread IDs and Arryabhatta is = %d\n",  Arryabhatta * id);
        //    Arryabhatta+=10;

    }

    
    return 0;
}
