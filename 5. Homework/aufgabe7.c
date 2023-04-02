#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int rc = fork();

    if (rc < 0) {         // fork failed return -1
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child process 0
        close(STDOUT_FILENO);
        printf("CHILD pid = %d\n", getpid());
    } else {              // parent process main
        wait(NULL);
    }
    return 0;
}
