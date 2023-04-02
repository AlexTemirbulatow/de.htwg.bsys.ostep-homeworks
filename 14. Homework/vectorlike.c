#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char* vector = (char*) malloc(sizeof(char));
    int n = 1;

    if (vector == NULL)
    {
        printf("Memory allocation failed!");
        exit(1);
    }

    while(1) 
    {
        char input;
        printf("Add one element to vector or quit (q): ");
        scanf(" %c", &input);

        if (input == 'q')
        {
            printf("final vector: ");
            for(int i = 0; i < n - 1; i++)
            {
                printf(" %c ", vector[i]);
            }
            printf("\n");
            free(vector);
            exit(1);
        }

        vector = (char*) realloc(vector, n * sizeof(char));
        vector[n - 1] = input;
        n++;
    }

    return 0;
}
