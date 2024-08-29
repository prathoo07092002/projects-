#include <stdio.h>
#include <omp.h>

int main() {
    // Define the family members' names
    const char* family_members[] = {"Prathamesh", "Sambhaji", "Smita", "Archana", "Pooja"};
    int num_members = 5;

    // Set the number of threads to the number of family members
    omp_set_num_threads(num_members);

    // Parallel region to print family members' names
    #pragma omp parallel
    {
        // Get the thread ID
        int thread_id = omp_get_thread_num();

        // Ensure the thread_id does not exceed the number of members
        if (thread_id < num_members) {
            // Print the name and the respective thread ID (job ID)
            printf("Thread %d: %s\n", thread_id, family_members[thread_id]);
        }
    }

    return 0;
}
