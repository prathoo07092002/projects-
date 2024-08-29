#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void add(int **vec1, int **vec2, int n) {
    #pragma omp parallel for schedule(dynamic, n/10)
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            vec1[i][j] = vec1[i][j] + vec2[i][j];
        }
    }
}

int main() {
    // Set the number of threads (optional)
    for (int i = 2; i <= 8; i += 2) {
        for (int j = 250; j <= 1000; j += 250) {
            omp_set_num_threads(i);

            // Allocate memory for vec1 and vec2
            int **vec1 = (int **)malloc(j * sizeof(int *));
            int **vec2 = (int **)malloc(j * sizeof(int *));
            for (int k = 0; k < j; k++) {
                vec1[k] = (int *)malloc(j * sizeof(int));
                vec2[k] = (int *)malloc(j * sizeof(int));
            }

            // Initialize vec1 and vec2
            for (int k = 0; k < j; k++) {
                for (int l = 0; l < j; l++) {
                    vec1[k][l] = l + k;
                    vec2[k][l] = l + k;
                }
            }

            // Measure execution time
            double s = omp_get_wtime();
            add(vec1, vec2, j);
            double e = omp_get_wtime();

            printf("Addition for size %d*%d with %d threads took %f seconds\n", j, j, i, e - s);

            // Free allocated memory
            for (int k = 0; k < j; k++) {
                free(vec1[k]);
                free(vec2[k]);
            }
            free(vec1);
            free(vec2);
        }
    }

    return 0;
}
