#include <stdio.h>
#include <mpi.h>
 
int main(int argc, char** argv) {
    // Initialize the MPI environment
    int size, rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Create an array of size 10 and initialize it with values from 0 to 9. 
    int arr[10]; 
    for (int i = 0; i < 10; i++) { 
        arr[i] = i; 
    }

    // Divide the array in equal-sized chunks and distribute them to all processes. 
    int n = 10/size; // number of elements per processor 

    // Send each process its portion of the array.  
    int *subarr = (int *)malloc(n*sizeof(int)); // subarray for each process  

    MPI_Scatter(arr, n, MPI_INT, subarr, n, MPI_INT, 0, MPI_COMM_WORLD);  

    // Perform some operation on the subarray  
    for (int i=0; i<n; i++) {  
        subarr[i] += rank*10;  
    }  

    // Gather all partial sums into the root process and print the result.  
    int *result = NULL;  

    if (rank == 0) {  

        result = (int *)malloc(10*sizeof(int));  

    }  

    MPI_Gather(subarr, n, MPI_INT, result, n ,MPI_INT ,0 ,MPI_COMM_WORLD);  

    if (rank == 0) {  

        printf("Result: ");  

        for (int i=0; i<10 ;i++) {  

            printf("%d ", result[i]); 

        } 

        printf("\n"); 

        free(result); 

    } 

    free(subarr); 

    MPI_Finalize();

    //End of parallel code
