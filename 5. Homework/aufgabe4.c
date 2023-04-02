#define _GNU_SOURCE
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

        char *myargs[] = {"/bin/ls", NULL};
        char* myargs2[] = {"ls", NULL};
        char* env[] = {NULL};
        
        //execl("/bin/ls", "/bin/ls", NULL);

        //execlp("ls", "ls", NULL);

        //execle("/bin/ls", "/bin/ls", NULL, env);

        //execv("/bin/ls", myargs);

        //execvp("ls", myargs2);

        execvpe("ls", myargs2, env);

    } else {              // parent process main
        wait(NULL);
    }
    return 0;
}
