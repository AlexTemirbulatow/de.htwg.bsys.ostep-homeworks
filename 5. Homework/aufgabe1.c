#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int* x = (int*) malloc(sizeof(int));
    *x = 100;

    int rc = fork();

    if (rc < 0) {         // fork failed return -1
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child process 0
        printf("CHILD  with pid: %d\n", (int) getpid());
        printf("CHILD  with x: %d\n", *x);
        *x = 1;
    } else {              // parent process main
        wait(NULL);
        printf("\nPARENT with pid: %d\n", (int) getpid());
        printf("PARENT with x: %d\n", *x);
        *x = 2;
    }
    printf("x is now set to: %d\n", *x);
    free(x);
    return 0;
}
