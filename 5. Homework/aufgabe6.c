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
        //int rc_wait = waitpid(getpid(), NULL, 0);
        printf("CHILD  pid = %d\n", (int) getpid());
        //printf("CHILD  rc_wait = %d\n", rc_wait);
    } else {              // parent process main
        int rc_wait = waitpid(rc, NULL, 0);
        printf("PARENT pid = %d\n", (int) getpid());
        printf("PARENT rc_wait = %d\n", rc_wait);
    }
    return 0;
}
