#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    int fd[2];
    if (pipe(fd) == -1) {
        printf("pipe failed\n");
        exit(1);
    }

    int c1, c2;

    (c1 = fork()) && (c2 = fork());

    if (c1 < 0 || c2 < 0) {         // fork failed return -1
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (c1 == 0) {           // child process 1
        
        close(fd[0]);
        int input;
        printf("Input a number: ");
        scanf("%d", &input);

        if(write(fd[1], &input, sizeof(int)) == -1 ) {
            printf("writing to pipe failed\n");
            exit(1);
        }
        close(fd[1]);

    } else if (c2 == 0) {           // child process 2
        
        close(fd[1]);
        int output;
        if (read(fd[0], &output, sizeof(int)) == -1) {
            printf("reading from pipe failed\n");
            exit(1);
        }
        printf("output from another child = %d\n", output);

    } else {                        // parent process main
        wait(NULL);
    }
    return 0;
}
