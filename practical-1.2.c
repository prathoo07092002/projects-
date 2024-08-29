#include <stdio.h>
#include <omp.h>

int main()
{int n;
    printf("enter no. of threads!!\n");
scanf("%d",&n);
omp_set_num_threads(n);
// for(int i=0;i<n;i++)
// {
//     printf("hello world %d \n",i);
// }
#pragma omp parallel
{
     printf("hello world %d \n",omp_get_thread_num());
}
}