#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void child_handler(int sig) {
    printf("Child process received signal %d\n", sig);
}

int main() {
    pid_t pid;
    int status;

    signal(SIGUSR1, child_handler);

    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(1);
    } 
    else if (pid == 0) {
        printf("Child process sending signal to parent\n");
        kill(getppid(), SIGUSR1);
        exit(0);
    } 
    else {
        printf("Parent process waiting for signal from child\n");
        pause();
        printf("Parent process received signal from child\n");
        wait(&status);
    }

    return 0;
}