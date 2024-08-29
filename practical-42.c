#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int count = 0; // Number of items in the buffer

void produce(int item) {
    // Simulate production of an item (could be more complex in a real case)
          while(count >= BUFFER_SIZE)
        {

        }
    #pragma omp critical
    {
  
        if (count < BUFFER_SIZE) {
            buffer[count] = item;
            count++;
            printf("Produced: %d, Buffer count: %d\n", item, count);
        }else{
printf("Buffer is full\n");
        }
    }
}

int consume() {
    int item = -1;
     while(count <=0)
        {
            
        }
    #pragma omp critical
    {
        if (count > 0) {
            item = buffer[count - 1];
            count--;
            printf("Consumed: %d, Buffer count: %d\n", item, count);
        } else{
printf("Buffer is empty\n");
        }
    }
    return item;
}

int main() {
    omp_set_num_threads(4); // Number of threads for the task

    #pragma omp parallel
    {
        int id = omp_get_thread_num();

        // Producer threads
        if (id % 2 == 0) {
            for (int i = 0; i < 10; i++) {
                produce(i + id * 10);
            }
        }

        // Consumer threads
        else {
            for (int i = 0; i < 10; i++) {
                consume();
            }
        }

        #pragma omp barrier // Synchronize threads before ending
    }

    return 0;
}
