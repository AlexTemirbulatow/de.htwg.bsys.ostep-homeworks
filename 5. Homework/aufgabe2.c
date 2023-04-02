#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    int fd = open("textfile.txt", O_RDWR);
    if (fd == -1) {
        printf("open failed\n");
        exit(1);
    }

    int rc = fork();

    if (rc < 0) {         // fork failed return -1
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // child process 0
        printf("CHILD  pid = %d\n", getpid());
        printf("CHILD  file descriptor number = %d\n", fd);

        char text[] = "CHILD";
        write(fd, text, sizeof(text));
    } else {              // parent process main
        printf("PARENT pid = %d\n", getpid());
        printf("PARENT file descriptor number = %d\n", fd);

        char text[] = "PARENT";
        write(fd, text, sizeof(text));
    }

    close(fd);
    return 0;
}
