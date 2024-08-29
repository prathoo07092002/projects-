#include <omp.h>
#include <stdio.h>
#include <math.h>

double calculate_pi(int num_steps, int num_threads) {
    double step = 1.0 / num_steps;
    double sum = 0.0;

    omp_set_num_threads(num_threads);
    #pragma omp parallel
    {
        double x;
        int id = omp_get_thread_num();
        int nthrds = omp_get_num_threads();
        double partial_sum = 0.0;

        for (int i = id; i < num_steps; i += nthrds) {
            x = (i + 0.5) * step;
            partial_sum += 4.0 / (1.0 + x * x);
        }

        #pragma omp atomic
        sum += partial_sum;
    }

    return step * sum;
}

int main() {
    int num_steps = 100000000; // Example number of steps
    int num_threads = 4; // Example number of threads

    double start_time = omp_get_wtime();
    double pi = calculate_pi(num_steps, num_threads);
    double end_time = omp_get_wtime();

    printf("Calculated Pi = %.15f\n", pi);
    printf("Time taken: %f seconds\n", end_time - start_time);

    return 0;
}