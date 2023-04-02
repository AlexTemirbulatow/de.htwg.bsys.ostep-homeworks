#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {

    int ppid = getpid();
    int rc = fork();

    if (rc < 0) {         // fork failed return -1
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child process 0
        printf("hello\n");
        kill(ppid, SIGCONT);
    } else {              // parent process main
        kill(ppid, SIGTSTP);
        printf("goodbye\n");
    }
    return 0;
}
