#include <stdio.h>
#include <omp.h>

// Parallel Fibonacci function
int parallel_fibonacci(int n) {
    int x, y;
    
    if (n <= 1) 
        return n;
    
    // Parallel region with tasking
    #pragma omp parallel
    {
        #pragma omp single
        {
          printf("single thread: %d for n=%d \n",omp_get_thread_num(),n);
            #pragma omp task shared(x)
         {printf("task1 thread no> %d \n",omp_get_thread_num()) ;  x = parallel_fibonacci(n - 1);}

            #pragma omp task shared(y)
            {printf("task2 thread no> %d \n",omp_get_thread_num()) ; y = parallel_fibonacci(n - 2);}

            #pragma omp taskwait // Wait for both tasks to complete
        }
    }

    return x + y;
}

int main() {
    int n = 6; // Example
    int result;

    // Set the number of threads
    omp_set_num_threads(4);

    // Measure execution time
    double start_time = omp_get_wtime();
    result = parallel_fibonacci(n);
    double end_time = omp_get_wtime();

    printf("Fibonacci of %d is %d\n", n, result);
    printf("Execution Time: %f seconds\n", end_time - start_time);

    return 0;
}
