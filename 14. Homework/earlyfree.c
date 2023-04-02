#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int* data = (int*) malloc(100 * sizeof(int));
    data[100] = 0;
    //free(data);
    free(&data[50]);
    printf("one value of the array: %d\n", data[15]);
    return 0;
}
