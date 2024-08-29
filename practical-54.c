#include <stdio.h>
#include <omp.h>

int main() {
    int total_sum = 0;  // Variable to hold the final total sum

    // Set the number of threads
    omp_set_num_threads(4);
    int partial_sum = 0;
    // Parallel region
    #pragma omp parallel private(partial_sum)
    {
      // Private partial sum for each thread
     partial_sum = 0;
        // Parallel for loop to compute partial sums
        #pragma omp for
        for (int i = 1; i <= 20; i++) {
            printf("thread no: %d , i:%d \n",omp_get_thread_num(),i);
            partial_sum += i;
        }

        // Critical section to safely update the total sum
        printf("for tn:%d partial_sum: %d\n",omp_get_thread_num(),partial_sum);
        #pragma omp critical
        {
            printf("\n\n\n partial_sum: %d",partial_sum);
            total_sum += partial_sum;
        }
    }

    // Print the final total sum
    printf("Total sum of the first 20 natural numbers: %d\n", total_sum);
     

    return 0;
}
