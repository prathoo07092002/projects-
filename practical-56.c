#include <stdio.h>
#include <omp.h>

void print_series_2() {
    for (int i = 0; i < 10; i++) {
        printf("2 ");
    }
    printf("\n");
}

void print_series_4() {
    for (int i = 0; i < 10; i++) {
        printf("4 ");
    }
    printf("\n");
}

int main() {
    // Set the number of threads
    omp_set_num_threads(2);

    // Parallel region
    #pragma omp parallel
    {
        // Determine the thread number
        int thread_num = omp_get_thread_num();

        if (thread_num == 0) {
            // Thread 0 prints series of 2
            print_series_2();
        } else if (thread_num == 1) {
            // Thread 1 prints series of 4
            print_series_4();
        }
    }

    return 0;
}
