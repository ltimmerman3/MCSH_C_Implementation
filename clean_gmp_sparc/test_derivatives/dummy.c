#include <stdio.h>
#include <stdlib.h>

/* Function looking at simple memory allocation
int main(int argc, char *argv[]) {
    // memory allocated for i as type int
    int i = 53;
    // memory location of i is stored in i_p
    int *i_p = &i;
    // This line causes a segfault when trying to print *i_p I believe because it is trying to access a value at a memory location == to i == 53.
    //This memory was never allocated for this process and may not even exist. 
    //int *i_p = i

    printf("%d %d %d %d %d", &i, i, *i_p, i_p, &i_p);

    return 0;
}
*/

/* Funtion looking at memory allocation for arrays
int main(int argc, char *argv[]) {
    // memory allocated for int array of size 5 and filled with these values
    int i[5] = {1,2,3,4,5};
    // memory location for the first element of the array i is stored in the pointer i_p
    //This will not cause a segfault
    int *i_p = i;
    // &i is start location in memory of array i
    //i is the same as &i
    // i_p is the same as &i_p, which is a memory location
    // *i_p is the value at memory location i_p, which is the first element of the array i
    // &i_p is the memory location of the pointer i_p
    i_p is the same, &i_p is the location in memory of the pointer i_p
    printf("%d %d %d %d %d", &i, i, *i_p, i_p, &i_p);

    return 0;
}
*/
/* Function to look at using free() with pointers*/
int main(int argc, char *argv[]) {
    
    double *test = malloc(sizeof(double)*4);
    double *test2 = malloc(sizeof(double)*4);
    for (int i=0; i<4; i++) {
        test[i] = 0.0;
        test2[i] = test[i];
    }
    printf("%d",test);
    free(test);
    printf("Finished");

    return 0;
}